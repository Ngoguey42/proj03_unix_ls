/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:40:00 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:40:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*cur;
	t_list	*next;

	if (!alst || !*alst)
		return ;
	cur = (*alst)->next;
	while (cur)
	{
		next = cur->next;
		cur->next = *alst;
		*alst = cur;
		cur = next;
	}
}
