/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 10:45:39 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/02 08:59:39 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ls_diresname_cmp(const void *s1, const void *s2)
{
	return (ft_strcmp((const char*)((const t_lsdire*)s1)->name,
				(const char*)((const t_lsdire*)s2)->name));
}

int		ls_direstime_cmp(const void *s1, const void *s2)
{
	const time_t	t1 = (const time_t)(((const t_lsdire*)s1)->sdate);
	const time_t	t2 = (const time_t)(((const t_lsdire*)s2)->sdate);
/* 	qprintf("sorting time for dires %d %d\n",  */
/* 			(const time_t)(((const t_lsdire*)s1)->sdate),  */
/* 			(const time_t)(((const t_lsdire*)s2)->sdate) */
/* ); */
	if (t2 == t1)
		return (ls_diresname_cmp(s1, s2));
	return (t2 - t1);
}

int		ls_trgsname_cmp(const void *s1, const void *s2)
{
	return (ft_strcmp((const char*)((const t_lstrg*)s1)->name,
				(const char*)((const t_lstrg*)s2)->name));
}

int		ls_trgstime_cmp(const void *s1, const void *s2)
{
	const time_t	t1 = (const time_t)(((const t_lstrg*)s1)->sdate);
	const time_t	t2 = (const time_t)(((const t_lstrg*)s2)->sdate);

	if (t2 == t1)
		return (ls_trgsname_cmp(s1, s2));
	return (t2 - t1);
}

void	ls_sort_targets(t_lstrg	**trgs, t_lsargs *args)
{
	if (!trgs || AND_SO(SONOSORT_MASK))
		return ;
/* 	qprintf("sorting for targets\n"); */
	if (AND_SO(SOTIME_MASK) || AND_SO(SOATIME_MASK))
		ft_tabsort((void**)trgs, &ls_trgstime_cmp, AND_SO(SOREV_MASK));
	else
		ft_tabsort((void**)trgs, &ls_trgsname_cmp, AND_SO(SOREV_MASK));
}

void    ls_sort_dires(t_lsdire **dires, t_lsargs *args)
{
	if (!dires || AND_SO(SONOSORT_MASK))
		return ;
/* 	qprintf("sorting for dires\n"); */
	if (AND_SO(SOTIME_MASK) || AND_SO(SOATIME_MASK))
		ft_tabsort((void**)dires, &ls_direstime_cmp, AND_SO(SOREV_MASK));
	else
		ft_tabsort((void**)dires, &ls_diresname_cmp, AND_SO(SOREV_MASK));
}
