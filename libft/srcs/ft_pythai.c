/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pythai.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:33:49 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:33:53 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_math.h"

div_t	ft_pythai(int v1, int v2)
{
	div_t	res;

	res.quot = ft_sqrtfloor(v1 * v1 + v2 * v2);
	res.rem = v1 * v1 + v2 * v2 - res.quot * res.quot;
	return (res);
}
