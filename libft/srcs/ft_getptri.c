
#include "libft.h"

t_ui64	ft_getptri(void * ptr)
{
	t_readptr	u;

	u.li = 0;
	u.p = ptr;
	return (u.li);
}
