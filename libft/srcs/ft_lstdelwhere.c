/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelwhere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:53:34 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:54:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!alst || *alst)
		return ;
	tmp = ft_lstpullfirst(alst);
	ft_lstdelone(&tmp, del);
}

void	ft_lstdellast(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!alst || *alst)
		return ;
	tmp = ft_lstpulllast(alst);
	ft_lstdelone(&tmp, del);
}

void	ft_lstdelprev(t_list **alst, t_list *lst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst || !lst || lst == *alst)
		return ;
	tmp = ft_lstpullprev(alst, lst);
	ft_lstdelone(&tmp, del);
}

void	ft_lstdelcur(t_list **alst, t_list *lst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst || !lst)
		return ;
	tmp = ft_lstpullcur(alst, lst);
	ft_lstdelone(&tmp, del);
}

void	ft_lstdelnext(t_list *lst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!lst || !lst->next)
		return ;
	tmp = ft_lstpullnext(lst);
	ft_lstdelone(&tmp, del);
}
