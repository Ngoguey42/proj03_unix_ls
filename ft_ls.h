/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:54:54 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/10 12:08:45 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <ft_error.h>
# include <dirent.h>
# include <sys/stat.h>
# include <limits.h>
# include <time.h>

# include <stdio.h> //debug
/* # define LSDEBUG //debug */

/*
** 'lRart' Mandatory flags in school's 'ft_ls' project.
** 'ABCFGbdfghnou1' Bonus flags.
*/
# define LS_FLAGS "ABCFGRabdfghlnortu1"
# define LS_NUMFL 19
# define MAJORDEV(dev) ((int)(((unsigned int)(dev) >> 24) & 0xFF))
# define MINORDEV(dev) ((int)((dev) & 0xFFFFFF))

/*
** ->text format masks
*/
# define AND_TF(ALIAS) (args->txfmt & (ALIAS))
# define TFCOLORS_MASK 0x01
# define TFNPRINT_MASK 0x02
# define TFESCAPE_MASK 0x04
# define TFSUFFIX_MASK 0x08
/*
** ->long format masks
*/
# define AND_LF(ALIAS) (args->lgfmt & (ALIAS))
# define LF_MASK 0x01
# define LFNOUID_MASK 0x02
# define LFNOGID_MASK 0x04
# define LFNUMERICID_MASK 0x08
# define LFHUMAN_MASK 0x10
# define LFATIME_MASK 0x20
/*
** ->small format masks
*/
# define AND_SF(ALIAS) (args->smfmt & (ALIAS))
# define SFONECOL_MASK 0x01
# define SFMULCOL_MASK 0x02
/*
** ->filter masks
*/
# define AND_FI(ALIAS) (args->filters & (ALIAS))
# define FISHOWHIDDEN_MASK 0x01
# define FISHOWDOTS_MASK 0x02
/*
** ->sorting masks
*/
# define AND_SO(ALIAS) (args->sorting & (ALIAS))
# define SOATIME_MASK 0x01
# define SOREV_MASK 0x02
# define SOTIME_MASK 0x04
# define SONOSORT_MASK 0x08
/*
** ->general masks
*/
# define AND_GE(ALIAS) (args->general & (ALIAS))
# define RECURSIVE_MASK 0x01
# define ASFILES_MASK 0x02

/*
** 'struct s_lstrg' One copy per 'main'.
** =>t_byte ...' Contains bitwise flags.		('t_byte' <=> 'unsigned char')
** 		Padding 't_lsargs' interpreted as uns chars in 'args_saving_pertype.c'.
** 		't_byte's mustn't be first in the struct.
** =>'**folders[1]' Contains at least one "." folder, read in 'argv'.
** =>'numf' Num folders.
** =>'*ex' Binary name.
** =>'*lformat' See 'main.c'
*/
typedef struct	s_lsargs
{
	size_t		numf;
	t_byte		txfmt;
	t_byte		lgfmt;
	t_byte		smfmt;
	t_byte		filters;
	t_byte		sorting;
	t_byte		general;
	char		**folders[1];
	char		*ex;
	char		*lformat;
	time_t		curtime;
	int			lfreq;
}				t_lsargs;
/*
** 'struct s_lstrg' One copy per 'folders' (see above)
** =>'*name' folder's string name.
** =>'p' 'opendir' return.
** =>'err' opendir's 'errno' value.
** =>'s' 'lstat' buffer, passed to 't_lsdire'. (see below)
** =>'sret' 'lstat' return value, passed to 't_lsdire'. (see below)
*/
typedef struct	s_lstrg
{
	DIR			*p;
	int			err;
	char		*name;
	struct stat	s;
	int			sret;
	char		is_hard_trg;
	time_t		sdate;
}				t_lstrg;
/*
** 'struct s_lsdire' One copy for each 'dirent' following a 'readir' call.
** =>'name' 'dirent' name;
** =>'ppath' parent path.
** =>'s' 'lstat' buffer.
** =>'sret' 'lstat' return value.
** =>'sdate' Sorting date, if required.
*/
typedef struct	s_lsdire
{
	char		name[PATH_MAX + 1];
	char		ppath[PATH_MAX + 1];
	struct stat	s;
	int			sret;
	time_t		sdate;
}				t_lsdire;


/*
** 'argv' parsing.
*/
int			ls_save_args(int ac, char **av, t_lsargs args[1]);
// void		ls_free_args(void *args);
int			ls_populate_saveargs_pertype(int (*ls_savearg_pertype[4])
											(char *arg, t_lsargs *args));
/*
** Printing.
*/
int			ls_print(t_lsargs *args);
void		ls_printfile_long(t_lsdire *dire, t_lsargs *args);
void        ls_push_smallformat(t_lsdire **dires, t_lsargs *args);
void		ls_print_acls(mode_t mode, char *name);
void		ls_print_dires(t_lsdire **dires, t_lsargs *args);
void		ls_print_directory(t_lstrg *trg, t_lsargs *args);
void        suffix(t_lsargs *args, mode_t all_bits, char *buf);
void        dire_colors(t_lsargs *args, mode_t all_bits, char *colr, char *eof);
void        ls_print_date(struct stat s, t_lsargs *args);

/*
** Sorting.
*/
int			ls_diresname_cmp(const void *s1, const void *s2);
void		ls_sort_targets(t_lstrg	**trgs, t_lsargs *args);
void		ls_sort_dires(t_lsdire **dires, t_lsargs *args);

/*
** Metatables.
*/
void		*ls_save_uid(const void *k);
void		*ls_save_gid(const void *k);
void		ls_deltrg(void *trg);

/*
** Debug
*/
void		printargs(t_lsargs *args);
void		print_lstrg(t_lstrg *trg);
void		print_lsdire(t_lsdire *dire);

#endif
