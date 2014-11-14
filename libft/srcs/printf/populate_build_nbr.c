/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_build_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:33:24 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 12:30:16 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 'build_nbr_0' error fallback.
** 'populate_build_nbr' populates the table handling each specifiers.
*/

static int	build_nbr_0(t_printf_part *part, va_list *args)
{
	(void)part;
	(void)args;
	return (1);
}

void		populate_build_nbr(int (*build_nbr[NUM_SPECIFIERS])
			(t_printf_part *part, va_list *args))
{
	build_nbr[0] = build_nbr_0;
	build_nbr[1] = build_nbr_1;
	build_nbr[2] = build_nbr_1;
	build_nbr[3] = build_nbr_3;
	build_nbr[4] = build_nbr_4;
	build_nbr[5] = build_nbr_5;
	build_nbr[6] = build_nbr_6;
	build_nbr[7] = build_nbr_0;
	build_nbr[8] = build_nbr_0;
	build_nbr[9] = build_nbr_0;
	build_nbr[10] = build_nbr_0;
	build_nbr[11] = build_nbr_0;
	build_nbr[12] = build_nbr_0;
	build_nbr[13] = build_nbr_13;
	build_nbr[14] = build_nbr_14;
	build_nbr[15] = build_nbr_15;
	build_nbr[16] = build_nbr_16;
	build_nbr[17] = build_nbr_17;
	build_nbr[18] = build_nbr_0;
	build_nbr[19] = build_nbr_19;
	build_nbr[20] = build_nbr_20;
	build_nbr[21] = build_nbr_21;
}
