
#include <stdio.h>
#include "libft.h"

#define MAX_TABLES	50
#define TABCC_DEBUG	0

/*
** 'ft_tabcc' handles up to MAX_TABLES tables stored in 't_tabdt'.
**		The function returns the requested tables's 't_tabdt'.
** 'request_index' searches or allow a new index for 'requested'.
*/

static void		debug_cc_printf(t_tabdt tables[MAX_TABLES], void **requested)
{
	int k;

	ft_printf("req{%Q.8p} => ", requested);
	for (k = 0; k < MAX_TABLES; k++)
	{
		if (tables[k].ptr || tables[k].size)
		{
			if (tables[k].ptr != requested)
				ft_printf("CC[%d]{%.8p}(%2u)  ", k,
								tables[k].ptr, tables[k].size);
			else
				ft_printf("CC[%d]{%Q.8p}(%2u)  ", k,
								tables[k].ptr, tables[k].size);
		}
	}
	ft_putendl("");
}

static int		request_index(t_tabdt tables[MAX_TABLES], void **requested)
{
	static int	i = 0;
	int			j;

	if (tables[i].ptr == requested)
		return (i);
	j = -1;
	i = 0;
	while (i < MAX_TABLES)
	{
		if (tables[i].ptr == requested)
			return (i);
		if (j < 0 && !tables[i].ptr)
			j = i;
		i++;
	}
	if (j >= 0)
		return (j);
	perror("Tables command center overflow");
	return (j);
}

t_tabdt	*ft_tabcc(void **requested)
{
	static t_tabdt	tables[MAX_TABLES];
	static int		initialized = 0;
	int				i;

	if (!initialized)
	{
		ft_bzero((void*)tables, MAX_TABLES);
		initialized++;
	}
	if (TABCC_DEBUG)
		debug_cc_printf(tables, requested);
	i = request_index(tables, requested);
	if (i < 0)
		return (NULL);
	return (&tables[i]);
}