/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewwhere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:28:30 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 18:28:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewfront(t_list **alst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	ft_lstpushfront(alst, new);
	return (new);
}

t_list	*ft_lstnewback(t_list **alst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	ft_lstpushback(alst, new);
	return (new);
}

t_list	*ft_lstnewprev(t_list **alst, t_list *lst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	ft_lstpushprev(alst, lst, new);
	return (new);
}

t_list	*ft_lstnewnext(t_list **alst, t_list *lst,
	void const *content, size_t content_size)
{
	t_list	*new;

	new = ft_lstnew(content, content_size);
	if (!new)
		return (NULL);
	ft_lstpushnext(alst, lst, new);
	return (new);
}
