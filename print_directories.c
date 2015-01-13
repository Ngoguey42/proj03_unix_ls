/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directories.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 08:45:48 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:41:55 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <ft_ls.h>

#define FNAME           (buf)
#define SEQU(STR)       ft_strequ(STR, FNAME)
#define ISDOT			(SEQU(".") || SEQU(".."))

#define FNAME2          (buf2)
#define SEQU2(STR)      ft_strequ(STR, FNAME2)
#define ISDOT2			(SEQU2(".") || SEQU2(".."))

#define ISHIDDEN		(*FNAME == '.' && !ISDOT)
#define HIDEHIDDEN      (!AND_FI(FISHOWHIDDEN_MASK) && ISHIDDEN)
#define LS_FILTERED_OUT (HIDEHIDDEN)

#define FNAME3          (d.name)
#define SEQU3(STR)      ft_strequ(STR, FNAME3)
#define ISDOT3			(SEQU3(".") || SEQU3(".."))
#define HIDEDOTS3       (!AND_FI(FISHOWDOTS_MASK) && ISDOT3)
#define ISHIDDEN3		(*FNAME3 == '.' && !ISDOT3)
#define HIDEHIDDEN3     (!AND_FI(FISHOWHIDDEN_MASK) && ISHIDDEN3)
#define LS_FILTERED_OUT3 (HIDEDOTS3 || HIDEHIDDEN3)

#define PUTHEADER		(args->numf > 1 || !trg->is_hard_trg)

static int	analyse_target
	(t_lstrg *trg, t_lsdire **dires[1], t_lsargs *args, size_t t[2])
{
	struct dirent	*direp;
	t_lsdire		d;
	char			buf[PATH_MAX + 1];

	errno = 0;
	while ((direp = readdir(trg->p)) != NULL)
	{
		if (errno)
			ft_error_fistrerrno(1, direp->d_name);
		else
		{
			ft_bzero((void*)&d, sizeof(t_lsdire));
			ft_strcpy(d.name, direp->d_name);
			ft_strcpy(d.ppath, trg->name);
			d.sret = lstat(ft_catpath(d.ppath, d.name, buf), &d.s);
			d.sdate = AND_SO(SOATIME_MASK) ? d.s.st_atime : d.s.st_mtime;
			t[0] += LS_FILTERED_OUT3 ? 0 : d.s.st_blocks;
			t[1] += LS_FILTERED_OUT3 ? 0 : 1;
			if (ft_tabaddm((void***)dires, (void*)&d, sizeof(t_lsdire)))
				ft_error_malloc();
		}
		errno = 0;
	}
	(void)args;
	return (0);
}

static void	put_headers(char *fn, char *sn, t_lsargs *args, int err)
{
	if (args->lfreq)
		ft_putchar('\n');
	if (AND_TF(TFESCAPE_MASK))
		ft_printf("%! $r:\n", fn);
	else if (AND_TF(TFNPRINT_MASK))
		ft_printf("%! $0r:\n", fn);
	else
		ft_printf("%! $0hr:\n", fn);
	if (err == EACCES)
		ft_error_fistrerrno(1, sn);
}

void		follow_directories(t_lstrg *trg, t_lsdire **dires, t_lsargs *args)
{
	t_lstrg	ntrg;
	DIR		*d;
	char	buf1[PATH_MAX + 1];
	char	buf2[PATH_MAX + 1];

	while (dires && *dires)
	{
		ft_catpath(trg->name, (*dires)->name, buf1);
		errno = 0;
		d = opendir(buf1);
		ft_filename((*dires)->name, buf2);
		if (errno == EACCES)
			put_headers(buf1, buf2, args, errno);
		if (d && ((*dires)->s.st_mode & S_IFMT) == S_IFDIR && !ISDOT2)
		{
			ft_bzero((void*)&ntrg, sizeof(t_lstrg));
			ntrg.err = errno;
			if (!(ntrg.name = ft_strdup(buf1)))
				ft_error_malloc();
			ntrg.p = d;
			ls_print_directory(&ntrg, args);
		}
		(void)(d ? closedir(d) : 1);
		dires++;
	}
}

static void	init(size_t total[2], t_lsdire **dires[1])
{
	ft_bzero(total, sizeof(total));
	*dires = NULL;
}

void		ls_print_directory(t_lstrg *trg, t_lsargs *args)
{
	t_lsdire	**dires[1];
	size_t		total[2];
	char		buf[PATH_MAX + 1];

	ft_filename(trg->name, buf);
	if (trg->err == 13)
	{
		if (!LS_FILTERED_OUT && PUTHEADER)
			put_headers(trg->name, trg->name, args, 13);
		return ;
	}
	init(total, dires);
	(void)analyse_target(trg, dires, args, total);
	ls_sort_dires(*dires, args);
	if (!LS_FILTERED_OUT)
	{
		if (PUTHEADER)
			put_headers(trg->name, NULL, args, 0);
		if (AND_LF(LF_MASK) && total[1] > 0)
			ft_printf("total %u\n", total[0]);
		ls_print_dires(*dires, args);
	}
	if (AND_GE(RECURSIVE_MASK))
		follow_directories(trg, *dires, args);
	ft_tabdel2((void***)dires);
}
