/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:05:50 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/14 14:31:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>
//debug file, todelete before last commit

void	printargs(t_lsargs *args)
{
	ft_printf("%p;%Qp ", args, &args->filters);

	ft_dprintf(2, 
			   "txfmt;tx[%Mhhb] lg[%Mhhb] sm[%Mhhb] fi[%Mhhb] so[%Mhhb] ge[%Mhhb]\n",
			   args->txfmt, 
			   args->lgfmt, 
			   args->smfmt, 
			   args->filters, 
			   args->sorting, 
			   args->general
		);
	
}
