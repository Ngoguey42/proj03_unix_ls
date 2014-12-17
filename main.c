/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:45:01 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/17 07:43:57 by ngoguey          ###   ########.fr       */
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

char	g_longtabformat[8][5] =
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

# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <ft_math.h>
# include <stdio.h>

#define tprintf(A1, A2)	qprintf("REF:");\
rref = sprintf(sref, A1, A2);\
qprintf("%2d:\"%s\"", rref, sref);\
qprintf("\nCUS:");\
rcus = ft_sprintf(scus, A1, A2);						\
qprintf("%2d:\"%s\"", rcus, scus);\
ft_myassert(ft_strequ(sref, scus));	  \
qprintf(" %s\n", A1)

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
