/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_small_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 08:52:01 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 10:40:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include <ft_ls.h>

#define FNAME           ((*dires)->name)
#define SEQU(STR)       ft_strequ(STR, FNAME)
#define HIDEDOTS        (!AND_FI(FISHOWDOTS_MASK) && (SEQU(".") || SEQU("..")))
#define HIDEHIDDEN      (!AND_FI(FISHOWHIDDEN_MASK) && *FNAME == '.')
#define LS_FILTERED_OUT (HIDEDOTS || HIDEHIDDEN)

/*
** Using 'ioctl' to get terminal informations.
**     struct winsize	w;
** 	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
**	i = !(AND_SF(SFONECOL_MASK) || !(w.ws_col || AND_SF(SFMULCOL_MASK)));
*/

static void	ls_printfile_fsmall(t_lsdire *dire, t_lsargs *args, int fmt)
{
	mode_t	all_bits;
	char	suf[2];
	char	colr[11];
	char	eof[6];

	all_bits = dire->s.st_mode;
	dire_colors(args, all_bits, colr, eof);
	suffix(args, all_bits, suf);
	if (AND_TF(TFESCAPE_MASK))
		ft_printf("%s%! $r%s%s", colr, dire->name, eof, suf);
	else if (AND_TF(TFNPRINT_MASK))
		ft_printf("%s%! $0r%s%s", colr, dire->name, eof, suf);
	else
		ft_printf("%s%! $0hr%s%s", colr, dire->name, eof, suf);
	if (fmt < 1)
		ft_putchar('\n');
}

void		ls_push_smallformat(t_lsdire **dires, t_lsargs *args)
{
	int				sfmt;
	struct winsize	w;

	args->lfreq = 1;
	ft_bzero(&w, sizeof(struct winsize));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	sfmt = !(AND_SF(SFONECOL_MASK) || !(w.ws_col || AND_SF(SFMULCOL_MASK)));

/* 	qprintf("salutlol sfmt%d  wscol%hu\n", sfmt, w.ws_col); */
	if (sfmt)
		ft_printfibuf("lscols", (int)w.ws_col, NULL);
	while (*dires)
	{
		if (!LS_FILTERED_OUT)
			ls_printfile_fsmall(*dires, args, sfmt);
		dires++;
	}
	if (sfmt)
	{
		ft_printffbuf("lscols", -1);
/* 		ft_putendl("\n"); */
	}
}
