/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:54:54 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/14 11:33:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <ft_error.h>

# define LS_FLAGS "ABCFGRabdfghlnortu1"

struct		s_lsargs
{
	t_byte	txfmt;
	t_byte	lgfmt;
	t_byte	smfmt;
	t_byte	filters;
	t_byte	sorting;
	t_byte	general;
	char	**folders;
};
typedef struct s_lsargs	t_lsargs;

t_lsargs	*ls_save_args(int ac, char **av);
void		ls_free_args(void *args);
int			ls_populate_saveargs_pertype(int (*ls_savearg_pertype[4])(char *arg,
													t_lsargs *args));

//debug
//# include <stdio.h>//debug

#endif
