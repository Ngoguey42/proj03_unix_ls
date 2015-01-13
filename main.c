/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:45:01 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:33:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** 'main'
** 1. Calls 'ls_save_args', in order to create a 't_lsargs' containing 'ft_ls'
** 		arguments. Might exit if invalid args or malloc fails.
** 2. Saves the long format specifications (see below).
** 3. Initializes an "uid" and "gid" metatable to avoid unnecessary
** 		calls of 'get(pwu|grg)id'.
** 4. Calls 'ls_print' handling printing through 'ft_printf'.
** 5. Frees left-overs.
*/

/*
** long table format for ft_printf buffer: g_longtabformat[i][j]
** #i columns.
** #j infos.
** j == 0 padding left.
** j == 1 padding right.
** j == 2 align text left.
** j == 3 empty.
** j == 4 empty.
*/

const char	g_longtabformat[8][5] =
{
	{0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0},
	{1, 1, 1, 0, 0},
	{1, 1, 1, 0, 0},
	{1, 1, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{-1, 0, 0, 0, 0}
};

void	ls_sort_targets(t_lstrg **trgs, t_lsargs *args)
{
	if (!trgs || AND_SO(SONOSORT_MASK))
		return ;
	if (AND_SO(SOTIME_MASK) || AND_SO(SOATIME_MASK))
		ft_tabsort((void**)trgs, &ls_trgstime_cmp, AND_SO(SOREV_MASK));
	else
		ft_tabsort((void**)trgs, &ls_trgsname_cmp, AND_SO(SOREV_MASK));
}

void	ls_sort_dires(t_lsdire **dires, t_lsargs *args)
{
	if (!dires || AND_SO(SONOSORT_MASK))
		return ;
	if (AND_SO(SOTIME_MASK) || AND_SO(SOATIME_MASK))
		ft_tabsort((void**)dires, &ls_direstime_cmp, AND_SO(SOREV_MASK));
	else
		ft_tabsort((void**)dires, &ls_diresname_cmp, AND_SO(SOREV_MASK));
}

int		main(int ac, char **av)
{
	t_lsargs	args[1];

	(void)ls_save_args(ac, av, args);
	args->lformat = (char*)g_longtabformat;
	args->curtime = time(NULL);
	ft_metaset("uid", &ls_save_uid, &ft_voiduintcmp, sizeof(uid_t));
	ft_metaset("gid", &ls_save_gid, &ft_voiduintcmp, sizeof(gid_t));
	ls_print(args);
	ft_tabdel((void***)args->folders);
	return (0);
}
