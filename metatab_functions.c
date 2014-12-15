/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metatab_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 11:02:43 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 14:38:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <ft_ls.h>

/*
** Functions passed to my libft's metatab-lib.
** These functions are 'key initializers'.
*/

void		*ls_save_uid(const void *k)
{
	struct passwd	*wd;
	char			*s;

	wd = getpwuid(*(uid_t*)k);
	if (!wd)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(char) * (1 + ft_strlen(wd->pw_name)))))
		ft_error_malloc();
	ft_strcpy(s, wd->pw_name);
	return ((void*)s);
}

void		*ls_save_gid(const void *k)
{
	struct group	*gp;
	char			*s;

	gp = getgrgid(*(gid_t*)k);
	if (!gp)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(char) * (1 + ft_strlen(gp->gr_name)))))
		ft_error_malloc();
	ft_strcpy(s, gp->gr_name);
	return ((void*)s);
}
