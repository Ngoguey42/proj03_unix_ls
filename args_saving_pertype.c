/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_saving_pertype.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:55:29 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/14 14:46:54 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#define FILTERS_PADDING (t_byte)((void*)&g_struct.filters - (void*)&g_struct)

/*
** One function for one behavior depending of the arg type and position.
*/

const t_lsargs	g_struct;

const t_byte	g_infos[][3][2] =
{
	{	{FILTERS_PADDING, SHOWHIDDEN_MASK},
		{0, 'A'}
	}, {{},
		{0, 'B'}
	}, {{},
		{0, 'C'}
	}, {{},
		{0, 'F'}
	}, {{},
		{0, 'G'}
	}, {{},
		{0, 'R'}
	}, {{FILTERS_PADDING, SHOWHIDDEN_MASK},
		{FILTERS_PADDING, SHOWDOTS_MASK},
		{0, 'a'}
	}, {{},
		{0, 'b'}
	}, {{},
		{0, 'd'}
	}, {{},
		{0, 'f'}
	}, {{},
		{0, 'g'}
	}, {{},
		{0, 'h'}
	}, {{},
		{0, 'l'}
	}, {{},
		{0, 'n'}
	}, {{},
		{0, 'o'}
	}, {{},
		{0, 'r'}
	}, {{},
		{0, 't'}
	}, {{},
		{0, 'u'}
	}, {{},
		{0, '1'}
	}
};

static int	error_type(char *arg, t_lsargs *args)
{
	ft_error_unknown();
	(void)arg;
	(void)args;
	return (1);
}

static int	flag_type(char *arg, t_lsargs *args)
{
	int	i;
	int	j;

	while (*++arg != '\0')
	{
		if ((i = ft_strcharlen(LS_FLAGS, *arg)) >= LS_NUMFL)
			ft_error_illegal_op(1, *arg, LS_FLAGS, &ls_free_args);
		j = -1;
		while (g_infos[i][++j][0] != 0)
			*(t_byte*)((void*)args + g_infos[i][j][0]) |= g_infos[i][j][1];
	}
	return (0);
}

static int	option_type(char *arg, t_lsargs *args)
{
	(void)arg;
	(void)args;
	return (1);
}

static int	target_type(char *arg, t_lsargs *args)
{
	(void)arg;
	(void)args;
	return (0);
}

int			ls_populate_saveargs_pertype(int (*ls_savearg_pertype[4])(char *arg,
											t_lsargs *args))
{
	ls_savearg_pertype[0] = &error_type;
	ls_savearg_pertype[1] = &flag_type;
	ls_savearg_pertype[2] = &option_type;
	ls_savearg_pertype[3] = &target_type;
	return (0);
}
