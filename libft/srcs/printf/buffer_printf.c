/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:48:59 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/17 10:26:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Aligne les arguments en colonnes.
** Affichage en tableau.
** Multibuffer en colonnes.
*/

/*
** 'ptf_buffer_infos'
** 'infos[0]' buffer status. 0 "off", 1 "cols"
** 'infos[1]' screen width.
** 'infos[2]' spacer char.
** 'infos[3]' spacer len.
** "setwid" sets screen_wid to 'arg2'. 0 default, -x previous, +x new.
** "getwid" returns 'screen_wid' or 'DEFAULT_SCREEN_WIDTH'.
** "setspacer" sets 'spacer' to 'arg2'. 0 default, -x previous, +x new.
*/

int		ptf_buffer_infos(char *arg1, int arg2)
{
	static int	infos[4] = {0, 0, 0, 1};

	if (ft_strequ("setwid", arg1))
		infos[1] = arg2 < 0 ? infos[1] : arg2;
	else if (ft_strequ("getwid", arg1))
		return (infos[1] == 0 ? DEFAULT_SCREEN_WIDTH : infos[1]);
	else if (ft_strequ("getstatus", arg1))
		return (infos[0]);
	else if (ft_strequ("setstatus", arg1))
		infos[0] = arg2;
	else if (ft_strequ("setspacer", arg1))
		infos[2] = (char)arg2 < 0 ? infos[2] : (int)(char)arg2;
	else if (ft_strequ("getspacer", arg1))
		return (infos[2] == 0 ? (int)DEFAULT_COLS_SPACER : infos[2]);
	else if (ft_strequ("setspwidth", arg1))
		infos[3] = arg2 < 0 ? infos[3] : arg2;
	else if (ft_strequ("getspwidth", arg1))
		return (infos[3]);
	return (0);
}

int		ft_fbuffer(char **ret, const char *arg1, int arg2)
{
	int	retval;

	if (ft_strequ("cols", (char*)arg1) &&
		ptf_buffer_infos("getstatus", arg2) == 1)
	{
		ptf_buffer_infos("setwid", arg2);
		retval = ptf_fflush_cols_buffer(ret, ptf_buffer_infos("getwid", 0));
		ptf_buffer_infos("setstatus", 0);
	}
	else
		return (-1);
	return (retval);
}

int		ft_ibuffer(char *arg1, int arg2)
{
	if (ft_strequ("cols", (char*)arg1) &&
		ptf_buffer_infos("getstatus", arg2) == 0)
	{
		ptf_buffer_infos("setstatus", 1);
		ptf_buffer_infos("setwid", arg2);
	}
	else
		return (-1);
	return (0);
}

int		ft_spacerbuffer(int arg1, int arg2)
{
	ptf_buffer_infos("setspacer", arg1);
	ptf_buffer_infos("setspwidth", arg2);
	return (0);
}
