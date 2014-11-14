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
	char	str[3];
	int		i;

	if (!lst)
		return ;
	ft_putstr("====lstprnt=====sizeof(t_list)=");
	ft_putnbr(sizeof(t_list));
	ft_putendl("===");
	i = 1;
	while (lst)
	{
		ft_putstr("lst[\033[35;46m");
		ft_utoa((unsigned int)i++, str, 10);
		ft_putnchar('0', 2 - ft_strlen(str));
		ft_putstr(str);
		ft_putstr("\033[0m]");
		ft_lstprntone(lst);
		lst = lst->next;
	}
}
