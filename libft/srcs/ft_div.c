/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:59:51 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 20:00:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_math.h"

div_t	ft_div(int num, int denom)
{
	div_t	res;

	res.quot = num / denom;
	res.rem = num % denom;
	if (num >= 0 && res.rem < 0)
	{
		res.quot++;
		res.rem -= denom;
	}
	return (res);
}
