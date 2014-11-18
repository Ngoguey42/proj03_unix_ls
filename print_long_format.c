/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 07:34:07 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/18 08:59:43 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <ft_ls.h>

/* 	t_lsdire	***dires; */

static t_bool	save_dire_info(t_lsdire **dires[1], struct dirent *dire)
{
	t_lsdire	infos;

	ft_strcpy(infos.name, dire->d_name);
	(void)dire;
	return (ft_tabaddm((void***)dires, (void*)&infos, sizeof(t_lsdire)));
}

t_bool			long_print_hardtg(char *p, t_lsargs *args)
{
	DIR				*dirptr;
	struct dirent	*dire;
	t_lsdire		**dires[1];

	errno = 0;
	if (!(dirptr = opendir(p)))
	{
		ft_error_fistrerrno(1, p);
		return (true);
	}
	if (args->numf > 0)
		ft_printf("%s:\n", p);
	ft_printf("total %u\n", 1337);
 	while ((dire = readdir(dirptr)))
	{
		save_dire_info(dires, dire);
		
	}
	(void)dirptr;
	(void)dire;
	return (true);
}

int			print_long_format(t_lsargs *args)
{
	int			i;
	char		**hard_targets;

	if (!AND_GE(ONLYFOLDERS_MASK))
	{
		hard_targets = *args->folders;
		while (*hard_targets)
		{
			long_print_hardtg(*hard_targets, args);
			hard_targets++;
		}
		
	}
	(void)i;
	return (0);
}
