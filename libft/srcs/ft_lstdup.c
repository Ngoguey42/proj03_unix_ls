/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:54:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:35:20 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*newa;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstdupone(lst);
	if (!new)
		return (NULL);
	newa = new;
	while ((lst = lst->next))
	{
		new->next = ft_lstdupone(lst);
		if (!new->next)
			return (NULL);
		new = new->next;
	}
	return (newa);
}
