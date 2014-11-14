/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:39:33 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:53:29 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDEFS_H
# define FT_TYPEDEFS_H

# include <stddef.h>

# ifndef T_BOOL
#  define T_BOOL

/*
**typedef enum					e_bool
**{
**	false,
**	true
**}								t_bool;
*/

# endif

typedef struct					s_list
{
	void						*content;
	size_t						content_size;
	struct s_list				*next;
}								t_list;

typedef unsigned char			t_byte;
typedef unsigned short			t_dbyte;
typedef int						t_i32;
typedef unsigned int			t_ui32;
typedef long long int			t_i64;
typedef unsigned long long int	t_ui64;

#endif
