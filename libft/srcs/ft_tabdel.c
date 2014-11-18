
#include <stdlib.h>
#include "libft.h"

int		ft_tabdel(void ***atab)
{
	t_tabdt	*s;

	// ft_printf("tabdel: ");
	if (!(s = ft_tabcc(*atab)))
		return (1);
	free(s->ptr);
	ft_bzero((void*)s, sizeof(t_tabdt));
	*atab = NULL;
	return (0);
}
