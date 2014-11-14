/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushwhere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:38:05 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:31:10 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Place NEW at the beginning of the list beginning with *ALST
**	if			alst != NULL
**	and if		new != NULL
*/

void	ft_lstpushfront(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && new)
	{
		if (*alst)
		{
			tmp = ft_lstlast(*alst);
			tmp->next = new;
		}
		else
			*alst = new;
	}
}

void	ft_lstpushnext(t_list **alst, t_list *lst, t_list *new)
{
	t_list	*tmp;

	if (alst && new
		&& ((*alst == NULL && lst == NULL) || (*alst != NULL && lst != NULL)))
	{
		if (lst == NULL)
			*alst = new;
		else
		{
			tmp = *alst;
			while (tmp && tmp != lst)
				tmp = tmp->next;
			if (tmp == lst)
			{
				new->next = lst->next;
				lst->next = new;
			}
		}
	}
}

void	ft_lstpushprev(t_list **alst, t_list *lst, t_list *new)
{
	t_list	*tmp;

	if (alst && new
		&& ((*alst == NULL && lst == NULL) || (*alst != NULL && lst != NULL)))
	{
		if (lst == *alst)
		{
			new->next = lst;
			*alst = new;
		}
		else
		{
			tmp = *alst;
			while (tmp->next && tmp->next != lst)
				tmp = tmp->next;
			if (tmp->next == lst)
			{
				tmp->next = new;
				new->next = lst;
			}
		}
	}
}
