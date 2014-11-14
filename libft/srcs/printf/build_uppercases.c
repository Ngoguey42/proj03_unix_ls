/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_uppercases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:32:22 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 12:32:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 'build_nbr_6' %X
** 'build_nbr_14' %A
*/

int		build_nbr_6(t_printf_part *part, va_list *args)
{
	int		i;
	char	c;

	build_nbr_5(part, args);
	i = 0;
	while ((c = part->nbr_ptr[i]))
		part->nbr_ptr[i++] = ft_toupper(c);
	return (1);
}

int		build_nbr_14(t_printf_part *part, va_list *args)
{
	int		i;
	char	c;

	build_nbr_13(part, args);
	i = 0;
	while ((c = part->nbr_ptr[i]))
		part->nbr_ptr[i++] = ft_toupper(c);
	return (1);
}
