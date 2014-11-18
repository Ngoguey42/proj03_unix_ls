/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:09:28 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:10:22 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprnt(t_list *lst)
{
	unsigned int	i;

	ft_putstr("====lstprnt=====sizeof(t_list)=");
	ft_putnbr(sizeof(t_list));
	ft_putendl("===");
	i = 1;
	while (lst)
	{
		ft_printf("lst[\033[35;46m%03u\033[0m]", i++);
		ft_lstprntone(lst);
		lst = lst->next;
	}
}
