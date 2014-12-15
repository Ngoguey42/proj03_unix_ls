/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 08:06:20 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 12:09:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <ft_ls.h>

#define FNAME			((*dires)->name)
#define SEQU(STR)		ft_strequ(STR, FNAME)
#define HIDEDOTS		(!AND_FI(FISHOWDOTS_MASK) && (SEQU(".") || SEQU("..")))
#define HIDEHIDDEN		(!AND_FI(FISHOWHIDDEN_MASK) && *FNAME == '.')
#define LS_FILTERED_OUT	(HIDEDOTS || HIDEHIDDEN)

/*
** 'analyse_targets' turn each 'folders' into an target entry in 'trgs'.
** 'print_bad_targets' prints invalid 'targets'.
** 'ls_print_dires' forks between 'long format' and 'small format'.
** 'print_files_targets' prints non-directory 'targets'. (or flag '-d')
**			as a single directory.
** 'ls_print' handles the 'targets' passed to ft_ls.
*/

/*
** 'ls_print_dires'
** 1. Forks between 'long format' and 'small format'.
** 2. Initialize 'ft_printf' buffering.
** 3. Calls printing for each 'dires' (Directory entries).
** 4. Flushes 'ft_printf' buffer for column printing.
*/

/*
** 'ls_print' handles the 'targets' passed to ft_ls.
** 1. Stores 'targets' infos in 't_lstrg **trgs[1]' (see ft_ls.h)
** 2. Calls error printing if 'target' doesn't exists.
** 3. Sorts 'targets'.
** 4. Calls printing for non-directory 'targets'. (or flag '-d')
** 5. Calls printing for directory 'targets'. (May call itself with '-R' flag)
*/

static int	analyse_targets(char **folders, t_lstrg **trgs[1], t_lsargs *args)
{
	DIR		*dirptr;
	t_lstrg	trg;

	while (*folders)
	{
		errno = 0;
		ft_bzero((void*)&trg, sizeof(t_lstrg));
		dirptr = opendir(*folders);
		trg.err = errno;
		trg.name = *folders;
		trg.is_hard_trg = 1;
		if (dirptr)
			trg.p = dirptr;
		trg.sret = lstat(*folders, &trg.s);
/* 		if (AND_SO(SOTIME_MASK) || AND_SO(SOATIME_MASK)) */
			trg.sdate = AND_SO(SOATIME_MASK) ? trg.s.st_atime : trg.s.st_mtime;
			trg.sdate = 19;
		if (ft_tabaddm((void***)trgs, (void*)&trg, sizeof(t_lstrg)))
			ft_error_malloc();
		folders++;
	}
	return (0);
}

static void	print_bad_targets(t_lstrg **trgs)
{
	while (*trgs)
	{
		print_lstrg(*trgs); //debug
		if ((*trgs)->err == 2)
			ft_error_fistrno(1, (*trgs)->name, (*trgs)->err);
		trgs++;
	}
}

void		ls_print_dires(t_lsdire **dires, t_lsargs *args)
{
	if (dires && *dires && AND_LF(LF_MASK))
	{
		ft_printfibuf("table", 0, (void*)args->lformat);
		while (*dires)
		{
			if (!LS_FILTERED_OUT)
				ls_printfile_long(*dires, args);
			dires++;
		}
		ft_printffbuf("table", 0);
	}
	else if (dires && *dires)
		ls_push_smallformat(dires, args);
}

static void	print_files_targets(t_lstrg **trgs, t_lsargs *args)
{
	t_lsdire	**dires[1];
	t_lsdire	dire;

	*dires = NULL;
	while (*trgs)
	{
		if ((AND_GE(ASFILES_MASK) && (*trgs)->err != 2) || (*trgs)->err == 20)
		{
			ft_bzero(&dire, sizeof(t_lsdire));
			ft_strcpy(dire.name, (*trgs)->name);
			dire.s = (*trgs)->s;
			dire.sret = (*trgs)->sret;
/* 			if (AND_SO(SOTIME_MASK) || AND_SO(SOATIME_MASK)) */
				dire.sdate = AND_SO(SOATIME_MASK) ? dire.s.st_atime :
					dire.s.st_mtime;
				dire.sdate = 17;
			if (ft_tabaddm((void***)dires, (void*)&dire, sizeof(t_lsdire)))
				ft_error_malloc();
		}
		trgs++;
	}
	ls_sort_dires(*dires, args);
	ls_print_dires(*dires, args);
	ft_tabdel2((void***)dires);
}

int			ls_print(t_lsargs *args)
{
	t_lstrg	**atrgs[1];
	t_lstrg	**trgs;

	(void)analyse_targets(*args->folders, atrgs, args);
	print_bad_targets(*atrgs);
	ls_sort_targets(*atrgs, args);
	print_files_targets(*atrgs, args);
	if (!AND_GE(ASFILES_MASK))
	{
		trgs = *atrgs;
		while (*trgs)
		{
			if ((*trgs)->err == 0)
				ls_print_directory(*trgs, args);
			trgs++;
		}
	}
	ft_tabdelf((void***)atrgs, &ls_deltrg);
	return (0);
}
