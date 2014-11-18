/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_saving_pertype.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:55:29 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/18 07:51:45 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

#define TXFMT_PADDING (t_byte)((void*)&g_struct.txfmt - (void*)&g_struct)
#define LGFMT_PADDING (t_byte)((void*)&g_struct.lgfmt - (void*)&g_struct)
#define SMFMT_PADDING (t_byte)((void*)&g_struct.smfmt - (void*)&g_struct)
#define FILTERS_PADDING (t_byte)((void*)&g_struct.filters - (void*)&g_struct)
#define SORTING_PADDING (t_byte)((void*)&g_struct.sorting - (void*)&g_struct)
#define GENERAL_PADDING (t_byte)((void*)&g_struct.general - (void*)&g_struct)

/*
** One function for one behavior depending of the arg type and position.
*/

const t_lsargs	g_struct;

const t_byte	g_infos[][3][2] =
{
	{	{FILTERS_PADDING, FISHOWHIDDEN_MASK},
		{0, 'A'}
	}, {{TXFMT_PADDING, TFNPRINT_MASK},
		{0, 'B'}
	}, {{SMFMT_PADDING, SFMULCOL_MASK},
		{0, 'C'}
	}, {{TXFMT_PADDING, TFSUFFIX_MASK},
		{0, 'F'}
	}, {{TXFMT_PADDING, TFCOLORS_MASK},
		{0, 'G'}
	}, {{GENERAL_PADDING, RECURSIVE_MASK},
		{0, 'R'}
	}, {{FILTERS_PADDING, FISHOWHIDDEN_MASK},
		{FILTERS_PADDING, FISHOWDOTS_MASK},
		{0, 'a'}
	}, {{TXFMT_PADDING, TFNPRINT_MASK},
		{TXFMT_PADDING, TFESCAPE_MASK},
		{0, 'b'}
	}, {{GENERAL_PADDING, ONLYFOLDERS_MASK},
		{0, 'd'}
	}, {{SORTING_PADDING, SONOSORT_MASK},
		{0, 'f'}
	}, {{LGFMT_PADDING, LF_MASK},
		{LGFMT_PADDING, LFNOUID_MASK},
		{0, 'g'}
	}, {{LGFMT_PADDING, LFHUMAN_MASK},
		{0, 'h'}
	}, {{LGFMT_PADDING, LF_MASK},
		{0, 'l'}
	}, {{LGFMT_PADDING, LF_MASK},
		{LGFMT_PADDING, LFNUMERICID_MASK},
		{0, 'n'}
	}, {{LGFMT_PADDING, LF_MASK},
		{LGFMT_PADDING, LFNOGID_MASK},
		{0, 'o'}
	}, {{SORTING_PADDING, SOREV_MASK},
		{0, 'r'}
	}, {{SORTING_PADDING, SOTIME_MASK},
		{0, 't'}
	}, {{LGFMT_PADDING, LFCTIME_MASK},
		{SORTING_PADDING, SOCTIME_MASK},
		{0, 'u'}
	}, {{SMFMT_PADDING, SFONECOL_MASK},
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
	int		i;
	int		j;
	void	*argsp;

	argsp = (void*)args;
	while (*++arg != '\0')
	{
		if ((i = ft_strcharlen(LS_FLAGS, *arg)) >= LS_NUMFL)
			ft_error_illegal_op(1, *arg, args->ex, &ls_free_args);
		j = -1;
		while (g_infos[i][++j][0] != 0)
			*(t_byte*)(argsp + g_infos[i][j][0]) |= g_infos[i][j][1];
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
	if (ft_tabadd((void***)args->folders, arg))
		ft_error_malloc();
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
