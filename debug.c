/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:05:50 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/17 08:37:33 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

#define LSARGSPRINT(KEY, SUB) ft_dprintf(2, "%20s(%"SUB")\n", #KEY, args->KEY)
#define TRGPRINT(KEY, SUB) ft_dprintf(2, #KEY"(%"SUB") ", trg->KEY)
#define DIREPRINT(KEY, SUB) ft_dprintf(2, #KEY"(%"SUB") ", dire->KEY)

t_lsargs	g_lsargs;

t_structspec	t_lsargsspec[] = {
	{"t_lsargs", sizeof(t_lsargs), 0},
	{"numf", sizeof(g_lsargs.numf), 1},
	{"txfmt", sizeof(g_lsargs.txfmt), 2},
	{"lgfmt", sizeof(g_lsargs.lgfmt), 2},
	{"smfmt", sizeof(g_lsargs.smfmt), 2},
	{"filters", sizeof(g_lsargs.filters), 2},
	{"sorting", sizeof(g_lsargs.sorting), 2},
	{"general", sizeof(g_lsargs.general), 2},
	{"folders", sizeof(g_lsargs.folders), 6},
	{"ex", sizeof(g_lsargs.ex), 5},
	{"lformat", sizeof(g_lsargs.lformat), 6},
	{NULL}
};

	// {"", sizeof(g_lsargs.), },
	
void	printargs(t_lsargs *args)
{
	int	i;
#ifndef LSDEBUG
	return ;
#endif
	ft_dprintf(2, "%Qs  %Us %p format;", "     =>", args->ex, args);
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
	ft_dprintf(2, "%Qs  (%u)folders {%p}  ", "     =>", args->numf, *args->folders);
	while ((*args->folders) && (*args->folders)[i])
	{
		ft_dprintf(2, "[%d]\"%s\"  ", i, (*args->folders)[i]);
		i++;
	}
	ft_putendl_fd("", 2);
}

void	print_lstrg(t_lstrg *trg)
{
#ifndef LSDEBUG
		return ;
#endif
	ft_dprintf(2, ":MAG:t_lstrg:eob:: {%p} ", (void*)trg);
	TRGPRINT(name, "25.25s");
	TRGPRINT(p, "#6.4hX");
	TRGPRINT(err, "2d");
	TRGPRINT(s, "#.4hX");
	TRGPRINT(sret, "2d");
	TRGPRINT(rlnk, "2d");
	ft_putendl_fd("", 2);
}

void	print_lsdire(t_lsdire *dire)
{
#ifndef LSDEBUG
		return ;
#endif
	ft_dprintf(2, ":BLU:t_lsdire:eob: : {%p} ", (void*)dire);
	DIREPRINT(name, "25.25s");
	DIREPRINT(ppath, "25.25s");
	DIREPRINT(s, "p");
	DIREPRINT(sret, "2d");
	DIREPRINT(sdate, "d");
	ft_putendl_fd("", 2);
}
