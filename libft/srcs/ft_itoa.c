/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:12:05 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 13:39:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"
#include <stdlib.h>

/*
** 'ft_itoa' converts a 'signed base 10 integer' to a 'C-string'.
** An optional negative sign if first written, then the number is writen
** backward and the string reversed afterward. This way the function also
** handles the INT_MIN value.
*/

char	*ft_itoa(int n)
{
	char	*str;
	char	*save;
	int		i;

	str = (char*)malloc(sizeof(char) * (ft_maxintlen(sizeof(int), 10) + 1));
	if (!(save = str))
		return (NULL);
	if (n < 0)
		*(str++) = '-';
	else if (n == 0)
		*(str++) = '0';
	i = 0;
	while (n != 0)
	{
		str[i++] = ABS(n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	ft_revstr(str);
	return (save);
}
