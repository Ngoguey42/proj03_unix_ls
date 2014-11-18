/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_small_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 08:52:01 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/17 15:22:12 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <ft_ls.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
//#include <sys/stat.h>

/*
** Using 'ioctl' to get terminal informations.
*/

char		*filesuffix_pertype(char buff[6], unsigned char type, long mode)
{
	ft_bzero(buff, 6);
	(void)type;
	(void)mode;
	return (buff);
}

char		*colorfmt_pertype(char buff[6], unsigned char type)
{
	ft_bzero(buff, 6);
	ft_strcpy(buff, ":gre:");
	(void)type;
	return (buff);
}

char		*build_name_format(struct dirent d, struct stat s, t_lsargs *args)
{
	char	*fmt;
	char	buff[11];

	if (!(fmt = (char*)ft_strnew(sizeof(char) * 15)))
		return (NULL);
	if (AND_TF(TFCOLORS_MASK))
		ft_strcat(fmt, colorfmt_pertype(buff, d.d_type));
	if (AND_TF(TFESCAPE_MASK))
		ft_strcat(fmt, "%S");
	else if (AND_TF(TFNPRINT_MASK))
		ft_strcat(fmt, "%S");
	else
		ft_strcat(fmt, "%s");
	if (AND_TF(TFSUFFIX_MASK))
		ft_strcat(fmt, filesuffix_pertype(buff, d.d_type, s.st_mode));
	if (AND_TF(TFCOLORS_MASK))
        ft_strcat(fmt, ":eof:");
	(void)s;
	return (fmt);
}

int			print_small_format(t_lsargs *args)
{
    struct winsize	w;
	int				i;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	i = !(AND_SF(SFONECOL_MASK) || !(w.ws_col || AND_SF(SFMULCOL_MASK)));
	if (i)
		(void)ft_ibuffer("cols", w.ws_col);
	(void)args;
	
	ft_printf("sal5555555555ut");
	ft_printf("sal9999999999999ut");
	ft_printf("saluOOO");
	ft_printf("saluOOO");
	ft_printf("s77777777777alut");
	ft_printf("saluOOO");
	ft_printf("saluOOO");
	ft_printf("saluOOOOOOOOOOLt");
	ft_printf("saluOOOOOOOOOOLt");
	ft_printf("saluOOOOOOOOOOLt");
	ft_printf("saluOOO");
	ft_printf("saluOOO");
	if (i)
		(void)ft_printfflush("cols", -1);
	ft_putchar('\n');
	return (0);
}
