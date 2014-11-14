/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_flushcols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:58:33 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 12:09:00 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"

/*
** 'ptf_cols_buffer'
** returns NULL if error.
** TODO: def a free content function.
*/

t_list			*ptf_cols_buffer(char *arg1, int arg2, void *arg3)
{
	static t_list **buf = NULL;

	if (!buf)
		if (!(buf = (t_list**)ft_memalloc(sizeof(t_list*))))
			return (NULL);
	if (ft_strequ("cleanbuf", arg1))
		ft_lstdel(buf, NULL);
	else if (ft_strequ("getbuf", arg1))
		return (*buf);
	else if (ft_strequ("pushone", arg1))
		if (!(ft_lstnewback(buf, arg3, (size_t)arg2)))
			return (NULL);
	return (*buf);
}

static size_t	calc_max_cols(t_list *lst, int screenwidth)
{
	size_t	total;
	int		first_line_width;
	int		spacer_width;

	total = 0;
	first_line_width = 0;
	spacer_width = ptf_buffer_infos("getspwidth", 0);
	while (lst)
	{
		first_line_width += ptf_calc_real_content_size(lst);
		if (first_line_width < screenwidth)
			total++;
		else
			break ;
		first_line_width += spacer_width;
		lst = lst->next;
	}
	return (total == 0 ? 1 : total);
}

int				narrow_down_num_cols(int *cols, int scw, t_list *l, size_t ncol)
{
	size_t	i;
	int		total;
	int		spacer_width;

	if (ncol < 2)
		return (0);
	ft_memset((void*)cols, 0, ncol * sizeof(int));
	i = 0;
	total = 0;
	spacer_width = ptf_buffer_infos("getspwidth", 0);
	while (l)
	{
		total -= cols[i];
		cols[i] = MAX(cols[i], ptf_calc_real_content_size(l));
		total += cols[i];
		if ((total + (int)(ncol - 1) * spacer_width) > scw)
			return (1);
		i = (i + 1) % ncol;
		l = l->next;
	}
	return (0);
}

int				ptf_fflush_cols_buffer(char **ret, int width)
{
	t_list	*lst;
	int		*cols_widths;
	size_t	num_cols;
	int		retval;

	if (!(lst = ptf_cols_buffer("getbuf", 0, 0)))
		return (-1);
	printf("(SALUT)\n");
	num_cols = calc_max_cols(lst, width);
	if (!(cols_widths = (int*)malloc(sizeof(int) * (num_cols))))
		return (-1);
	while (narrow_down_num_cols(cols_widths, width, lst, num_cols))
		num_cols--;
	retval = ptf_cols_concat_string(ret, lst, cols_widths, num_cols);
	if (retval < 0)
		return (-1);
	ptf_cols_buffer("cleanbuf", 0, 0);
	return (retval);
}
