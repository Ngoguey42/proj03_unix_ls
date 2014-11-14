/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:42:48 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 11:09:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ISIZE sizeof(int)

/*
** 'ft_memcpy' copies the 'n' first bytes of 'source' to 'destination'.
** The first loop copies ISIZE bytes at a time.
** The second loop deals with trailing bytes.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	t;
	int		*dst_ip;
	char	*dst_cp;

	if (n == 0 || dst == src)
		return (dst);
	dst_ip = (int*)dst;
	t = n / ISIZE;
	while (t--)
	{
		*dst_ip++ = *(int*)src;
		src += ISIZE;
	}
	dst_cp = (char*)dst_ip;
	t = n % ISIZE;
	while (t--)
		*dst_cp++ = *(char*)src++;
	return (dst);
}
