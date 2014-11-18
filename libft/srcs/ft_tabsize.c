
#include "libft.h"

size_t	ft_tabsize(void **tab)
{
	t_tabdt	*s;

	ft_printf("tabsiz: ");
	if (!(s = ft_tabcc(tab)))
		return (0);
	return (s->size);
}
