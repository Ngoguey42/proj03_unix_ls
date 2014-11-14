/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpullwhere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:23:47 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:24:49 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*ft_lstpullfirst(t_list **alst)
{
	t_list	*tmp;

	if (!alst || !*alst)
		return (NULL);
	tmp = *alst;
	*alst = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_list	*ft_lstpulllast(t_list **alst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!alst || !*alst)
		return (NULL);
	tmp2 = NULL;
	tmp = *alst;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp2)
		tmp2->next = NULL;
	else
		*alst = NULL;
	return (tmp);
}

t_list	*ft_lstpullprev(t_list **alst, t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!alst || !*alst || !lst || lst == *alst)
		return (NULL);
	tmp2 = NULL;
	tmp = *alst;
	while (tmp->next && tmp->next != lst)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (NULL);
	if (tmp2)
		tmp2->next = lst;
	else
		*alst = lst;
	tmp->next = NULL;
	return (tmp);
}

t_list	*ft_lstpullcur(t_list **alst, t_list *lst)
{
	t_list	*tmp;

	if (!alst || !*alst || !lst)
		return (NULL);
	if (*alst == lst)
		*alst = lst->next;
	else
	{
		tmp = *alst;
		while (tmp->next && tmp->next != lst)
			tmp = tmp->next;
		if (tmp->next == NULL)
			return (NULL);
		tmp->next = lst->next;
	}
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstpullnext(t_list *lst)
{
	t_list	*tmp;

	if (!lst || !lst->next)
		return (NULL);
	tmp = lst->next;
	lst->next = tmp->next;
	tmp->next = NULL;
	return (tmp);
}
