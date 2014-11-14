/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 08:52:13 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/14 11:38:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

/*
** Version 1 of ft_error.
*/

/*
** 'ft_error_illegal_op' functions index:
** 0 for default.
** 1 for ls.
** 'ft_error_illegal_op' modes:
** 0x1 flags
** 0x2 files
*/

char		g_names[][6] = {"", "ft_ls"};
const int	g_modes[] = {0x0, 0x03};

void	ft_error_illegal_op(int fi, char o, char *fl, void (*f)(void *p))
{
	ft_dprintf(2, "%s: illegal option -- %c", g_names[fi], o ? o : '-');
	if (g_modes[fi] & 0x03)
	{
		ft_dprintf(2, "\nusage: %s", g_names[fi]);
		if (g_modes[fi] & 0x01)
			ft_dprintf(2, " [-%s]", fl);
		if (g_modes[fi] & 0x02)
			ft_dprintf(2, " [file ...]");
	}
	ft_putchar_fd('\n', 2);
	if (f != NULL)
		f(NULL);
	exit(EXIT_FAILURE);
}

void	ft_error_malloc(void)
{
	ft_putendl_fd("Malloc failed, exiting program.", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_unknown(void)
{
	ft_putendl_fd("Unknown error, exiting program.", 2);
	exit(EXIT_FAILURE);
}
