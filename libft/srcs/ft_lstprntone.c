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

#define FMT1 "==ptr:%R.10*p"
#define FMT2 "======next:%N.10*p"
#define FMT3 "===content:%R.10*p"
#define FMT4 "======size:%03u"
#define FMT5 "=====\n"

void	ft_lstprntone(t_list *lst)
{
	ft_printf(FMT1""FMT2""FMT3""FMT4""FMT5,
		(void*)lst, (void*)lst->next, lst->content, lst->content_size);
}
