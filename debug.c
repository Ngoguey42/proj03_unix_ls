/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:05:50 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/18 07:47:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>
//debug file, todelete before last commit

void	printargs(t_lsargs *args)
{
	int	i;

	ft_dprintf(2, "%Qs  %Us format;", "=>", args->ex);
	ft_dprintf(2, 
			   "tx[%Mhhb] lg[%Mhhb] sm[%Mhhb] fi[%Mhhb] so[%Mhhb] ge[%Mhhb]\n",
			   args->txfmt, 
			   args->lgfmt, 
			   args->smfmt, 
			   args->filters, 
			   args->sorting, 
			   args->general
		);
	i = 0;
	ft_dprintf(2, "%Qs  (%u)folders {%p}  ", "=>", args->numf, *args->folders);
	while ((*args->folders) && (*args->folders)[i])
	{
		ft_dprintf(2, "[%d]\"%s\"  ", i, (*args->folders)[i]);
		i++;
	}
	ft_putendl("");
}
