
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define TAB_INCREMENT 1

/*
** 'ft_tabadd' stores 'new' in '*atab' and may ask for a table resize, storing
**		the new 'first pointer' in 'atab'.
** 'realloc_table' reallocates the table represented in a 't_tabdt'
** ('realloc', stdlib's function is never allowed).
*/


void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!(new = malloc(new_size)))
		return (NULL);
	if (new_size < old_size)
		old_size = new_size;
	if (ptr && old_size > 0)
	{
		ft_memcpy(new, ptr, old_size);
		free(ptr);
	}
	return (new);
}	

void	*ft_crealloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!(new = malloc(new_size)))
		return (NULL);
	if (new_size < old_size)
		old_size = new_size;
	if (ptr && old_size > 0)
	{
		ft_memcpy(new, ptr, old_size);
		free(ptr);
		ft_bzero(new + old_size, new_size - old_size);
	}
	else
		ft_bzero(new + old_size, new_size);
	return (new);
}

static int	realloc_table(t_tabdt	*s)
{
	void	**new;

	new = (void**)ft_crealloc(s->ptr, sizeof(void*) * s->size,
				sizeof(void*) * (s->size + 1 + TAB_INCREMENT));
	if (!new)
	{
		perror("'realloc_tables' malloc failed");
		return (1);
	}
	s->ptr = new;
	return (0);
}

int		ft_tabadd(void ***atab,  void *new)
{
	t_tabdt	*s;

	if (!(s = ft_tabcc(*atab)))
		return (1);
	if (s->size % TAB_INCREMENT == 0)
	{
		if (realloc_table(s))
			return (1);
		*atab = s->ptr;
	}
	s->ptr[s->size++] = new;
	return (0);
}

void	*ft_memdup(void *p, size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, p, size);
	return (new);
}

t_bool	ft_tabaddm(void ***atab, void *new, size_t size)
{
	void *newm;

	if (!(newm = ft_memdup(new, size)))
		return (false);
	return ((t_bool)ft_tabadd(atab, newm));
}
