/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:54:54 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/18 08:58:00 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <ft_error.h>

# define LS_FLAGS "ABCFGRabdfghlnortu1"
# define LS_NUMFL 19

/*
** ->text format masks
*/
# define TFCOLORS_MASK 0x01
# define TFNPRINT_MASK 0x02
# define TFESCAPE_MASK 0x04
# define TFSUFFIX_MASK 0x08
/*
** ->long format masks
*/
# define LF_MASK 0x01
# define LFNOUID_MASK 0x02
# define LFNOGID_MASK 0x04
# define LFNUMERICID_MASK 0x08
# define LFHUMAN_MASK 0x10
# define LFCTIME_MASK 0x20
/*
** ->small format masks
*/
# define SFONECOL_MASK 0x01
# define SFMULCOL_MASK 0x02
/*
** ->filter masks
*/
# define FISHOWHIDDEN_MASK 0x01
# define FISHOWDOTS_MASK 0x02
/*
** ->sorting masks
*/
# define SOCTIME_MASK 0x01
# define SOREV_MASK 0x02
# define SOTIME_MASK 0x04
# define SONOSORT_MASK 0x08
/*
** ->general masks
*/
# define RECURSIVE_MASK 0x01
# define ONLYFOLDERS_MASK 0x02

# define AND_TF(ALIAS) (args->txfmt & (ALIAS))
# define AND_LF(ALIAS) (args->lgfmt & (ALIAS))
# define AND_SF(ALIAS) (args->smfmt & (ALIAS))
# define AND_FI(ALIAS) (args->filters & (ALIAS))
# define AND_SO(ALIAS) (args->sorting & (ALIAS))
# define AND_GE(ALIAS) (args->general & (ALIAS))

struct		s_lsargs
{
	char	*ex;
	char	**folders[1];
	size_t	numf;
	t_byte	txfmt;
	t_byte	lgfmt;
	t_byte	smfmt;
	t_byte	filters;
	t_byte	sorting;
	t_byte	general;
};
typedef struct s_lsargs	t_lsargs;

struct		s_lsdire
{
	char	name[256];
};
typedef struct s_lsdire t_lsdire;

t_lsargs	*ls_save_args(int ac, char **av);
void		ls_free_args(void *args);
int			ls_populate_saveargs_pertype(int (*ls_savearg_pertype[4])(char *arg,
													t_lsargs *args));
int			print_long_format(t_lsargs *args);
int			print_small_format(t_lsargs *args);
int			print_target_format(t_lsargs *args);

void    printargs(t_lsargs *args);


#endif
