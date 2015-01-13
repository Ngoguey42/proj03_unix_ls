/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format_deps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:43:06 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:36:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char get_type_char(mode_t fmt)
{
	if (fmt == S_IFDIR)
		return ('d');
	if (fmt == S_IFSOCK)
		return ('s');
	if (fmt == S_IFCHR)
		return ('c');
	if (fmt == S_IFIFO)
		return ('p');
	if (fmt == S_IFLNK)
		return ('l');
	if (fmt == S_IFBLK)
		return ('b');
	return ('-');
}

static char get_right(mode_t field, size_t pos, char *name)
{
	if (pos < 9 && pos % 3 == 1)
		return ((field & (1 << (9 - pos))) ? 'r' : '-');
	if (pos < 9 && pos % 3 == 2)
		return ((field & (1 << (9 - pos))) ? 'w' : '-');
	if (pos > 0 && pos % 3 == 0)
	{
		if (field & (1 << (9 - pos)))
		{
			if (field & (1 << (12 - pos / 3)))
				return (pos / 3 < 3 ? 's' : 't');
			return ('x');
		}
		else if (field & (1 << (12 - pos / 3)))
			return (pos / 3 < 3 ? 'S' : 'T');
	}
	if (pos == 0)
		return (get_type_char(field & S_IFMT));
	if (pos == 10 && listxattr(name, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	else if (pos == 10)
		return ('\0');
	return ('-');
}

void		ls_print_acls(mode_t mode, char *name)
{
	char	acls[12];
	size_t	i;

	ft_bzero((void*)acls, 12);
	i = 0;
	while (i < 11)
	{
		acls[i] = get_right(mode, i, name);
		i++;
	}
	ft_printf("%s", acls);
}
