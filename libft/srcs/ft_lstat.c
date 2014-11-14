/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:51:30 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:32:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, size_t nbr)
{
	if (!lst || nbr == 0)
		return (NULL);
	while (lst && --nbr)
		lst = lst->next;
	return (lst);
}
