/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:39:10 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 12:01:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "ft_typedefs.h"

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define MAX(V1, V2) ((V1) > (V2) ? V1 : V2)
# define MIN(V1, V2) ((V1) < (V2) ? V1 : V2)
# define BASE_NBRS "0123456789abcdefghijklmnopqrstuvwxyz"

# ifndef IEEE_DOUBLE_BIG_ENDIAN
#  define IEEE_DOUBLE_BIG_ENDIAN 0
# endif

# if IEEE_DOUBLE_BIG_ENDIAN

union					u_dbl_extract
{
	struct
	{
		unsigned char	sig:1;
		unsigned short	exp:11;
		t_ui32			manh:20;
		t_ui32			manl:32;
	}					s;
	double				d;
};

union					u_nan_dbl_extract
{
	struct
	{
		unsigned char	sig:1;
		unsigned short	exp:11;
		unsigned char	nan:1;
		t_ui32			manh:19;
		t_ui32			manl:32;
	}					s;
	double				d;
};

union					u_dbl_shape
{
	struct
	{
		t_ui32			manh:32;
		t_ui32			manl:32;
	}					s;
	double				d;
};

# else

union					u_dbl_extract
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:20;
		unsigned short	exp:11;
		unsigned char	sig:1;
	}					s;
	double				d;
};

union					u_nan_dbl_extract
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:19;
		unsigned char	nan:1;
		unsigned short	exp:11;
		unsigned char	sig:1;
	}					s;
	double				d;
};

union					u_dbl_shape
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:32;
	}					s;
	double				d;
};
# endif

typedef union u_dbl_extract		t_dbl_extract;
typedef union u_nan_dbl_extract	t_nan_dbl_extract;
typedef union u_dbl_shape		t_dbl_shape;

# define M_INFINITY (1.0/0.0)
# define M_MINFINITY (-1.0/0.0)
# define M_NAN (0.0/0.0)

#endif
