/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format_deps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:43:06 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 16:06:23 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <sys/xattr.h>

#ifdef XATTR_NOFOLLOW
# define LISTXATTRARGS name, NULL, 0, XATTR_NOFOLLOW
#else
# define LISTXATTRARGS name, NULL, 0
#endif

/*
** ACL details: 5 types over 10 chars :
** 0 1 2 3 1 2 3 1 2 4 5  (types)
** 0 1 2 3 4 5 6 7 8 9 10 (chars)
** - - - - - - - - - - ' '
** c r w x r w x r w x @
** l     s     s     t +
** d     S     S     T
** s
** c
** b
*/

static char	get_type_char(mode_t most_bits)
{
	if (most_bits == S_IFDIR)
		return ('d');
	if (most_bits == S_IFSOCK)
		return ('s');
	if (most_bits == S_IFCHR)
		return ('c');
	if (most_bits == S_IFIFO)
		return ('p');
	if (most_bits == S_IFLNK)
		return ('l');
	if (most_bits == S_IFBLK)
		return ('b');
	return ('-');
}

static char	get_right(mode_t all_bits, size_t pos, char *name)
{
	if (pos < 9 && pos % 3 == 1)
		return ((all_bits & (1 << (9 - pos))) ? 'r' : '-');
	if (pos < 9 && pos % 3 == 2)
		return ((all_bits & (1 << (9 - pos))) ? 'w' : '-');
	if (pos > 0 && pos % 3 == 0)
	{
		if (all_bits & (1 << (9 - pos)))
		{
			if (all_bits & (1 << (12 - pos / 3)))
				return (pos / 3 < 3 ? 's' : 't');
			return ('x');
		}
		else if (all_bits & (1 << (12 - pos / 3)))
			return (pos / 3 < 3 ? 'S' : 'T');
	}
	if (pos == 0)
		return (get_type_char(all_bits & S_IFMT));
	if (pos == 10 && listxattr(LISTXATTRARGS) > 0)
		return ('@');
	else if (pos == 10)
		return (' ');
	return ('-');
}

void		ls_print_acls(mode_t all_bits, char *name)
{
	char	acls[12];
	size_t	i;

	ft_bzero((void*)acls, 12);
	i = 0;
	while (i < 11)
	{
		acls[i] = get_right(all_bits, i, name);
		i++;
	}
	ft_printf("%s", acls);
}

void		ls_print_date(struct stat s, t_lsargs *args)
{
	char	buf[30];
	time_t	t;
	time_t	difft;

	ft_bzero((void*)buf, 30 * sizeof(char));
	t = AND_LF(LFATIME_MASK) ? s.st_atime : s.st_mtime;
	difft = args->curtime - t;
	ft_strlcpy(buf, ctime(&t), 30);
	if (difft > 15778800)
	{
		buf[11] = ' ';
		ft_memmove(buf + 12, buf + 20, 4);
	}
	buf[16] = '\0';
	ft_printf("%s", buf + 4);
	
}
