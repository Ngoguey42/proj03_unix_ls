/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:17:15 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 15:00:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ==================> PRINTF HEART <================== **
*/

/*
** 'concat_parts' concatenates all 't_printf_part' together.
** 'build_specifiers' builds %substitutions.
** 'ft_getprintf' is the function called by every vprintf functions.
*/

static int	concat_parts(t_printf_part **beginning, char **ret)
{
	t_printf_part	*current;
	size_t			len;

	current = *beginning;
	len = final_string_size(current);
	if (!(*ret = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (-1);
	string_cat(*ret, 0);
	while (current)
	{
		string_cat((char*)current->str_ptr, current->str_size);
		string_cat(current->nbr_ptr, current->nbr_size);
		current = current->next;
	}
	string_cat(NULL, 0);
	return (len);
}

static int	build_specifiers(t_printf_part **beginning, va_list *args)
{
	t_printf_part	*current;
	int				(*tab[NUM_SPECIFIERS])(t_printf_part *part, va_list *args);

	populate_build_nbr(tab);
	current = *beginning;
	while (current)
	{
		if (current->specifier)
		{
			if (tab[current->specifier](current, args) < 1)
				return (0);
		}
		if (current->flags & COLORS_FLAGS_FIELD)
		{
			if (add_color_flag(current) < 1)
				return (0);
		}
		current = current->next;
	}
	return (1);
}

int			ft_getprintf(char **ret, const char *format, va_list args)
{
	t_printf_part	**beginning;
	va_list			args2;
	int				i;


	if ((beginning = malloc(sizeof(t_printf_part*))) == NULL)
		return (-1);
	if (parse_format(format, beginning) <= 0)
		return (-1);
	va_copy(args2, args);
/*     printf("        [DEBUG;s]"); fflush(stdout); */
	if (build_specifiers(beginning, &args2) <= 0)
		return (-1);
/*     printf("        [DEBUG;e]"); fflush(stdout); */
	i = concat_parts(beginning, ret);

	if (ptf_buffer_infos("getstatus", 0) == 1)
	{
		ptf_cols_buffer("pushone", i + 1, (void*)*ret);
		i = 0;
		*ret = NULL;
	}

	return (i);
}
