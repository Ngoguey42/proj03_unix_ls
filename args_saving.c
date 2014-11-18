/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_saving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 08:29:47 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/18 07:50:22 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_ls.h>

/*
** 'get_arg_type' returns the raw arg type.
** 'get_saving_status' first sets *status, and return the arg type.
** 'ls_save_args' saves args in a 't_lsargs', and ret a pointer to it, or exits.
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
	int		argtype;

	argtype = get_arg_type(curarg);
	// ft_printf("foundtype(%d)", argtype);
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

static int	strcmp_toconstvoid(const void *s1, const void *s2)
{
	return (ft_strcmp((const char*)s1, (const char*)s2));
}

t_lsargs	*ls_save_args(int ac, char **av)
{
	t_lsargs	*ret;
	int			status;
	int			argtype;
	int			(*ls_savearg_pertype[4])(char *arg, t_lsargs *save);

	ls_populate_saveargs_pertype(ls_savearg_pertype);
	if (!(ret = (t_lsargs*)ft_memalloc(sizeof(t_lsargs))))
		ft_error_malloc();
	ls_free_args((void*)ret);
	status = 0;
	ret->ex = *av;
	while (ac-- > 1)
	{
		av++;
		// ft_printf("parsing arg(%8s), prevstatus(%d){ ", *av, status);
		argtype = get_saving_status(&status, *av);
		if (ls_savearg_pertype[argtype](*av, ret))
			ft_error_illegal_op(1, 0, ret->ex, &ls_free_args);
		// ft_printf(" }rettype(%d)", argtype);
		// ft_printf("newstatus(%d)", status);
		// ft_putendl("");
	}
	if (!*ret->folders)
		if (ft_tabadd((void***)ret->folders, "."))
			ft_error_malloc();
	ret->numf = ft_tabsize((void**)*ret->folders);
 	ft_tabsort((void**)*ret->folders, &strcmp_toconstvoid);
	printargs(ret);
	return (ret);
}
