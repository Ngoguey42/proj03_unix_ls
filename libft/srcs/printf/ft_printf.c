/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:22:21 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/17 10:21:02 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int     ft_vsprintf(char *str, const char *format, va_list args)
{
    int     len;
    char    *ret;

    ret = NULL;
    len = ft_getprintf(&ret, format, args);
    if ((!ret && len > 0) || len < 0)
        return (-1);
    else if (!ret)
        return (0);
    ft_memcpy(str, ret, len + 1);
    return (len);
}

int     ft_sprintf(char *str, const char *format, ...)
{
    va_list     ap;
    int         ret;

    va_start(ap, format);
    ret = ft_vsprintf(str, format, ap);
    va_end(ap);
    return (ret);
}

int     ft_vprintf(const char *format, va_list arg)
{
    int     len;
    char    **ret;

    ret = malloc(sizeof(char*));
    if (!ret)
        return (-1);
    len = ft_getprintf(ret, format, arg);
    if ((!*ret && len > 0) || len < 0)
        return (-1);
    else if (!*ret)
        return (0);
    if (len > 0)
        ft_putstr(*ret);
    free(ret);
    return (len);
}

int     ft_printf(const char *format, ...)
{
    va_list     ap;
    int         ret;

    va_start(ap, format);
    ret = ft_vprintf(format, ap);
    va_end(ap);
    return (ret);
}

int     ft_vdprintf(int fd, const char *format, va_list arg)
{
    int     len;
    char    **ret;

    ret = malloc(sizeof(char*));
    if (!ret)
        return (-1);
    len = ft_getprintf(ret, format, arg);
    if (len >= 0)
        ft_putstr_fd(*ret, fd);
    free(ret);
    return (len);
}

int     ft_dprintf(int fd, const char *format, ...)
{
    va_list     ap;
    int         ret;

    va_start(ap, format);
    ret = ft_vdprintf(fd, format, ap);
    va_end(ap);
    return (ret);
}

int		ft_printfflush(const char *type, int wid)
{
	char	*s;

	if (ft_fbuffer(&s, type, wid) < 0)
		return (-1);
	return (ft_printf(s));
}
