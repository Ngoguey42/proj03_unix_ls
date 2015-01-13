/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_saving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 08:29:47 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:17:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** 'get_arg_type' returns the raw arg type.
** 'get_saving_status' first sets *status, and return the arg type.
** 'ls_save_args' saves args in the 't_lsargs', or exits.
*/

/*
** 'get_arg_type' types:
** 0, error
** 1, flag
** 2, option
** 3, target
*/
/*
** 'get_saving_status' statuses:
** 0, start
** 1, flags / options
** 2, targets
** 9, error
*/
/*
** 'ls_save_args' steps:
** 1. Populates 'ls_savearg_pertype' from 'args_saving_pertype.c' file.
** 2. bzeroes 't_lsargs args'
** 3. Saves binary name for further use.
** 4. Parses argvs (see above), exits if unknown flag.
** 5. Adds "." directory if none were found.
** 6. Alphabetically sorts directories.
*/

static int	get_arg_type(char *curarg)
{
	size_t	len;

	len = ft_strlen(curarg);
	if (!len)
		return (0);
	if (len >= 2 && *curarg == '-' && curarg[1] == '-')
		return (2);
	else if (*curarg == '-' && len > 1)
		return (1);
	return (3);
}

static int	get_saving_status(int *status, char *curarg)
{
	int	argtype;

	argtype = get_arg_type(curarg);
	if (!argtype)
		*status = 9;
	else if (*status < 2 && argtype <= 2)
		*status = 1;
	else if (*status < 2)
		*status = 2;
	if (*status == 2)
		return (3);
	return (argtype);
}

int			ls_save_args(int ac, char **av, t_lsargs args[1])
{
	int	status;
	int	argtype;
	int	(*ls_savearg_pertype[4])(char *arg, t_lsargs *save);

	(void)ls_populate_saveargs_pertype(ls_savearg_pertype);
	ft_bzero((void*)args, sizeof(t_lsargs));
	status = 0;
	args->ex = *av;
	while (ac-- > 1)
	{
		av++;
		argtype = get_saving_status(&status, *av);
		if (ls_savearg_pertype[argtype](*av, args))
			ft_error_illegal_op(1, 0, args->ex, NULL);
	}
	if (!*args->folders)
		if (ft_tabadd((void***)args->folders, "."))
			ft_error_malloc();
	args->numf = ft_tabsize((void**)*args->folders);
	ft_tabsort((void**)*args->folders, &ft_voidstrcmp, 0);
	return (0);
}
