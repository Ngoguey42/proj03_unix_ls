/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convsz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:36:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/17 09:22:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putexpchar(int exp, char *buffer)
{
	if (exp < 3)
		*buffer = 'B';
	else if (exp < 6)
		*buffer = 'K';
	else if (exp < 9)
		*buffer = 'M';
	else if (exp < 12)
		*buffer = 'G';
	else if (exp < 15)
		*buffer = 'T';
	else if (exp < 18)
		*buffer = 'P';
	else if (exp < 21)
		*buffer = 'E';
	else if (exp < 24)
		*buffer = 'Z';
	else if (exp < 27)
		*buffer = 'Y';
	else
		*buffer = '?';
}

static void	apply_decimal_notation(char *buffer, int *tmp, float *fl)
{
	buffer[0] = '0' + *tmp;
	buffer[1] = '.';
	*fl = (*fl - (float)*tmp) * 10;
	*tmp = (int)ft_floor((double)*fl);
	buffer[2] = '0' + *tmp;	
}

int			ft_convsz(t_ui64 bytes, char *buffer)
{
	float	fl;
	int		tmp;
	int		exp;

/* 	qprintf("%6llu ", bytes); */
	ft_bzero((void*)buffer, 5);
	exp = 0;
	fl = (float)bytes;
	while (!(fl < 1000))
	{
/* 		qprintf("%6.0f ", fl); */
		fl /= 1024;
		exp += 3;
	}
/* 	qprintf("%5.2f ", fl); */
	tmp = (int)ft_floor((double)fl);
/* 	qprintf("%d ", tmp); */
	if (tmp >= 10 || exp == 0)
		ft_itoa_c(tmp, buffer, 10);
	else
		apply_decimal_notation(buffer, &tmp, &fl);
	ft_putexpchar(exp, buffer + ft_strlen(buffer));
/* 	qprintf("%.2f\n", fl - (float)tmp); */
	if (!(fl - (float)tmp < 0.5))
		ft_roundup_b10(buffer);
/* 	qprintf("\n"); */
	return (exp);
}
