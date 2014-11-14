/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprntone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:12:32 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:12:52 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprntone(t_list *lst)
{
	char	str[9];

	if (!lst)
		return ;
	ft_putstr("\033[0m==ptr:0x");
	ft_lutoa((unsigned long long int)lst, str, 16);
	ft_putnchar('0', 8 - ft_strlen(str));
	ft_putstr(str);
	ft_putstr("======next:0x");
	ft_lutoa((unsigned long long int)lst->next, str, 16);
	ft_putnchar('0', 8 - ft_strlen(str));
	ft_putstr(str);
	ft_putstr("\033[0m===content:\033[31;43m0x");
	ft_lutoa((unsigned long long int)lst->content, str, 16);
	ft_putnchar('0', 8 - ft_strlen(str));
	ft_putstr(str);
	ft_putstr("\033[0m======size:\033[31;43m");
	ft_lutoa((unsigned long long int)lst->content_size, str, 10);
	ft_putnchar('0', 3 - ft_strlen(str));
	ft_putstr(str);
	ft_putendl("\033[0m=====\033[31;43m");
	ft_memprint(lst->content, lst->content_size);
	ft_putstr("\033[0m");
}
