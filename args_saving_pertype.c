/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_saving_pertype.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:55:29 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/14 11:26:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** One function for one behavior depending of the user input detected.
*/

static int	error_type(char *arg, t_lsargs *args)
{
	ft_error_unknown();
	(void)arg;
	(void)args;
	return (1);
}

static int	flag_type(char *arg, t_lsargs *args)
{

	(void)arg;
	(void)args;
	return (0);
}

static int	option_type(char *arg, t_lsargs *args)
{
	(void)arg;
	(void)args;
	return (1);
}

static int	target_type(char *arg, t_lsargs *args)
{

	(void)arg;
	(void)args;
	return (0);
}

int			ls_populate_saveargs_pertype(int (*ls_savearg_pertype[4])(char *arg,
											t_lsargs *args))
{
	ls_savearg_pertype[0] = &error_type;
	ls_savearg_pertype[1] = &flag_type;
	ls_savearg_pertype[2] = &option_type;
	ls_savearg_pertype[3] = &target_type;
	return (0);
}
