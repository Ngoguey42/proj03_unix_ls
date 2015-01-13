/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 10:45:39 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 10:33:59 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ls_diresname_cmp(const void *s1, const void *s2)
{
	const t_lsdire	*s1p = (const t_lsdire*)s1;
	const t_lsdire	*s2p = (const t_lsdire*)s2;

	return (ft_strcmp(s1p->name, s2p->name));
}

int		ls_direstime_cmp(const void *s1, const void *s2)
{
	const time_t	t1 = (const time_t)(((const t_lsdire*)s1)->sdate);
	const time_t	t2 = (const time_t)(((const t_lsdire*)s2)->sdate);

	if (t2 == t1)
		return (ls_diresname_cmp(s1, s2));
	return (t2 - t1);
}

int		ls_trgsname_cmp(const void *s1, const void *s2)
{
	const t_lstrg	*s1p = (const t_lstrg*)s1;
	const t_lstrg	*s2p = (const t_lstrg*)s2;

	return (ft_strcmp(s1p->name, s2p->name));
}

int		ls_trgstime_cmp(const void *s1, const void *s2)
{
	const time_t	t1 = (const time_t)(((const t_lstrg*)s1)->sdate);
	const time_t	t2 = (const time_t)(((const t_lstrg*)s2)->sdate);

	if (t2 == t1)
		return (ls_trgsname_cmp(s1, s2));
	return (t2 - t1);
}
