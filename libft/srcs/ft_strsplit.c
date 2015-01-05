/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:27:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:13:18 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strsplit' allocates a table of strings contaning parts of a
** 'C-string' splitted with a delimiter.
** *
** Updated with ft_strsplit_s, previous code did not compile 26/12/14.
*/

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	char	delim[2];

	delim[0] = c;
	delim[1] = '\0';
	if (ft_strsplit_s(s, (char*)&delim, &ret))
		return (NULL);
	return (ret);
}
