/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:45:01 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 13:04:45 by ngoguey          ###   ########.fr       */
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

/* union lol */
/* { */
/* 	unsigned long long	i; */
/* 	double		d; */
/* }; */


int		main(int ac, char **av)
{
	t_lsargs	args[1];


/* 	char *sref, *scus; */

/* 	sref = ft_strnew(500); */
/* 	scus = ft_strnew(500); */
/* 	int rref, rcus; */
/* 	ADD_NBR_BITS(0x0000000000000001); */
/* 	ADD_NBR_BITS(0x000FFFFFFFFFFFFF); */

/* 	union lol loli; */

/* 	loli.i = 0x0000000000000001; */
/* 	tprintf("%15.1a", loli.d); */

/* 	loli.i = 0x000FFFFFFFFFFFFF; */
/* 	tprintf("%15.1a", loli.d); */



/* 	tprintf("%15f", -0.0); */
/* 	tprintf("%15f", ); */
/* 	tprintf("%15f", +0.0); */
/* 	tprintf("% 15f", -0.0); */
/* 	tprintf("%-15f", +0.0); */
/* 	tprintf("%+15f", -0.0); */
/* 	tprintf("%015f", +0.0); */
/* 	tprintf("%#15f", +0.0); */


/* 	tprintf("%15.0f", -0.0); */
/* 	tprintf("%15.0f", +0.0); */
/* 	tprintf("%15.1f", -0.0); */
/* 	tprintf("%15.1f", +0.0); */
/* 	tprintf("%15.1f", M_NAN); */
/* 	tprintf("%15.1f", M_INFINITY); */
/* 	tprintf("%15.1f", -M_INFINITY); */

/* 	tprintf("%.0f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.1f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.2f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.3f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.4f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.5f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.6f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.7f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.8f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.9f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.10f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.11f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.12f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.13f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.14f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.15f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.16f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.17f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.18f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.19f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.20f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.21f", 87451874517845617894561874561.9876543210); */
/* 	tprintf("%.22f", 87451874517845617894561874561.9876543210); */


/* 	tprintf("%.308f", 0x1.0p-1074); */
/* 	tprintf("%.308f", 0x1.ffffffffffffep-1023); */




/* 	return 0; */
	(void)ls_save_args(ac, av, args);
	args->lformat = (char*)g_longtabformat;
	args->curtime = time(NULL);
	ft_metaset("uid", &ls_save_uid, &ft_voiduintcmp, sizeof(uid_t));
	ft_metaset("gid", &ls_save_gid, &ft_voiduintcmp, sizeof(gid_t));
	ls_print(args);
	ft_tabdel((void***)args->folders);
	return (0);
}
