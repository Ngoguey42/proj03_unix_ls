/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 07:34:07 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:26:15 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <ft_ls.h>
#include <unistd.h>

#ifdef S_IFWHT
# define CHECKWHITEOUT (most_bits == S_IFWHT)
#else
# define CHECKWHITEOUT (0)
#endif

/*
** Calls 'ft_printf' for each 7 columns of the long format.
*/

static void	print_groups(t_lsargs *args, struct stat s)
{
	char	*tmp;

	if (AND_LF(LFNOUID_MASK))
		ft_printf("");
	else if (AND_LF(LFNUMERICID_MASK) ||
			!(tmp = (char*)ft_metaget("uid", (void*)&s.st_uid)))
		ft_printf("%hu", s.st_uid);
	else
		ft_printf("%s", tmp);
	if (AND_LF(LFNOGID_MASK))
		ft_printf("");
	else if (AND_LF(LFNUMERICID_MASK) ||
			!(tmp = (char*)ft_metaget("gid", (void*)&s.st_gid)))
		ft_printf("%hu", s.st_gid);
	else
		ft_printf("%s", tmp);
}

void		suffix(t_lsargs *args, mode_t all_bits, char *buf)
{
	mode_t	most_bits;

	ft_bzero(buf, 2 * sizeof(char));
	if (!AND_TF(TFSUFFIX_MASK))
		return ;
	if ((most_bits = all_bits & S_IFMT) == S_IFDIR)
		*buf = '/';
	else if (most_bits == S_IFSOCK)
		*buf = '=';
	else if (most_bits == S_IFIFO)
		*buf = '|';
	else if (most_bits == S_IFLNK)
		*buf = '@';
	else if (CHECKWHITEOUT)
		*buf = '%';
	else if (all_bits & S_IXUSR || all_bits & S_IXGRP || all_bits & S_IXOTH)
		*buf = '*';
	return ;
}

void		dire_colors(t_lsargs *args, mode_t all_bits, char *colr, char *eof)
{
	mode_t	most_bits;

	ft_bzero(colr, 11 * sizeof(char));
	ft_bzero(eof, 6 * sizeof(char));
	if (!AND_TF(TFCOLORS_MASK))
		return ;
	most_bits = all_bits & S_IFMT;
	if (most_bits == S_IFDIR)
		ft_strcpy(colr, (all_bits & S_ISVTX) ? ":GRE::bla:" : ":cya::lig:");
	else if (most_bits == S_IFLNK)
		ft_strcpy(colr, ":mag:");
	else if (most_bits == S_IFSOCK)
		ft_strcpy(colr, ":gre:");
	else if (all_bits & S_IXUSR || all_bits & S_IXGRP || all_bits & S_IXOTH)
		ft_strcpy(colr, (all_bits & S_ISUID) ? ":RED::bla:" : ":red:");
	else if (most_bits == S_IFBLK)
		ft_strcpy(colr, ":CYA::blu:");
	else if (most_bits == S_IFCHR)
		ft_strcpy(colr, ":YEL::blu:");
	if (*colr)
		ft_strcpy(eof, ":eof:");
}

static void	print_name(t_lsdire *dire, t_lsargs *args, mode_t all_bits, char *p)
{
	char	suf[2];
	char	colr[11];
	char	eof[6];
	char	lnk[PATH_MAX + 1 + 4];

	dire_colors(args, all_bits, colr, eof);
	suffix(args, all_bits, suf);
	if ((all_bits & S_IFMT) == S_IFLNK)
	{
		ft_bzero(lnk, (PATH_MAX + 1 + 4) * sizeof(char));
		readlink(p, ft_strcpy(lnk, " -> ") + 4, PATH_MAX + 1);
	}
	else
		*lnk = '\0';
	if (AND_TF(TFESCAPE_MASK))
		ft_printf("%s%! $r%s%s%! $r\n", colr, dire->name, eof, suf, lnk);
	else if (AND_TF(TFNPRINT_MASK))
		ft_printf("%s%! $0r%s%s%! $0r\n", colr, dire->name, eof, suf, lnk);
	else
		ft_printf("%s%! $0hr%s%s%! $0hr\n", colr, dire->name, eof, suf, lnk);
}

void		ls_printfile_long(t_lsdire *dire, t_lsargs *args)
{
	struct stat	s;
	char		buf[30];
	char		fullpath[PATH_MAX + 1];

	ft_catpath(dire->ppath, dire->name, fullpath);
	args->lfreq = 1;
	s = dire->s;
	ls_print_acls(s.st_mode, fullpath);
	ft_printf("%hu", s.st_nlink);
	print_groups(args, s);
	if (((s.st_mode & S_IFMT) == S_IFCHR) || ((s.st_mode & S_IFMT) == S_IFBLK))
		ft_printf("%3u,%4u", MAJORDEV(s.st_rdev), MINORDEV(s.st_rdev));
	else if (AND_LF(LFHUMAN_MASK))
		ft_printf(" %s", (ft_convsz((t_ui64)s.st_size, buf), buf));
	else
		ft_printf("%llu", s.st_size);
	ft_bzero((void*)buf, 30 * sizeof(char));
	ls_print_date(s, args);
	print_name(dire, args, s.st_mode, fullpath);
}
