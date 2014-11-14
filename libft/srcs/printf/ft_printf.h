/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:35:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 12:28:02 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>

/*
** TODOLIST
** recheck les arguments size
** take care of memory leaks in add_color_flags.c
*/

/*
** FLAGS
*/
# define CHARS_FLAGS "-+ #0!$MNOPQRU\'"
# define MINU_MASK 0x1
# define PLUS_MASK 0x2
# define SPAC_MASK 0x4
# define HASH_MASK 0x8
# define ZERO_MASK 0x10
# define EXCL_MASK 0x20
# define DOLL_MASK 0x40
# define APOS_MASK 0x4000

# define FIRT_C_FLAG_ID		7
# define NUM_COLOR_FLAGS 	7
# define COLORS_FLAGS_FIELD	0x3F80
# define TYPE_OF_FLAGS		unsigned short
# define SIZE_OF_FLAGS		(sizeof(TYPE_OF_FLAGS) * 8)
/*
** INFO
*/
# define WSTA_MASK	0x1
# define PSTA_MASK	0x2
# define PNUM_MASK	0x4
/*
** LENGTH, SPECIFIERS
*/
# define CHARS_LENGTH		"jztLhl"
# define NUM_DBL_CHAR_LEN	2
# define CHARS_SPECIFIERS	"diuoxXfFeEgGaAcspn%bS"
# define NUM_SPECIFIERS		21 + 1
/*
** MACROS
*/
# define AND_F(x) (part->flags & x)
# define AND_I(x) (part->info & x)
# define PAD_CHAR part->flags & ZERO_MASK ? '0' : ' '
/*
** MISC
*/
# define NUM_C_TAGS 33
# define NUM_SMALLC_TAGS 7
/*
** BUFFERS
*/
# define DEFAULT_SCREEN_WIDTH 200
# define DEFAULT_COLS_SPACER '.'
# define DEFAULT_FILLER '_'

/*
** Main struct (linked list). (One for each '%' in format)[+1].
** 'str_ptr' pointer in format. Following format beginning or
** previous specifier, 'str_size' to locate the end.
** 'nbr_ptr' string resulting of the %subsitution, 'nbr_size' long.
** 'flags', 'info', 'width', 'precision', 'length', 'specifier' read in format.
** 'next' points next link.
*/
typedef struct				s_printf_part
{
	const char				*str_ptr;
	size_t					str_size;
	char					*nbr_ptr;
	int						nbr_size;
	TYPE_OF_FLAGS			flags;
	unsigned char			info;
	int						width;
	int						precision;
	unsigned char			length;
	unsigned char			specifier;
	struct s_printf_part	*next;
}							t_printf_part;

typedef union				u_readbit
{
	unsigned char			u;
	char					s;
}							t_readbit;

/*
** For external use.
*/
int		ft_getprintf(char **ret, const char *format, va_list args);
int		ft_ibuffer(char *arg1, int arg2);
int		ft_fbuffer(char **ret, const char *arg1, int arg2);

int		parse_format(const char *format, t_printf_part **beginning);
int		final_string_size(t_printf_part *current);
int		get_color_tag_index(const char *str);
int		add_color_flag(t_printf_part *p);
void	string_cat(char *s1, size_t len);

int		store_opt_1(char c, t_printf_part *part);
int		store_opt_2(char c, t_printf_part *part);
int		store_opt_3(char c, t_printf_part *part);
int		store_opt_5(char c, t_printf_part *part);
int		store_opt_6(char c, t_printf_part *part);
int		store_opt_7(char c, t_printf_part *part);
int		store_opt_8(char c, t_printf_part *part);

/*
** Specifiers building.
*/
void	populate_build_nbr(int(*build_nbr[NUM_SPECIFIERS])
			(t_printf_part *part, va_list *args));
int		build_nbr_1(t_printf_part *part, va_list *args);
int		build_nbr_3(t_printf_part *part, va_list *args);
int		build_nbr_4(t_printf_part *part, va_list *args);
int		build_nbr_5(t_printf_part *part, va_list *args);
int		build_nbr_6(t_printf_part *part, va_list *args);
int		build_nbr_13(t_printf_part *part, va_list *args);
int		build_nbr_14(t_printf_part *part, va_list *args);
int		build_nbr_15(t_printf_part *part, va_list *args);
int		build_nbr_16(t_printf_part *part, va_list *args);
int		build_nbr_17(t_printf_part *part, va_list *args);
int		build_nbr_19(t_printf_part *part, va_list *args);
int		build_nbr_20(t_printf_part *part, va_list *args);
int		build_nbr_21(t_printf_part *part, va_list *args);
t_i64	get_signed_varg(t_byte length, va_list *args);
t_ui64	get_unsigned_varg(t_byte length, va_list *args);

/*
** %i %d %u %x %X %o %p dependency.
*/
void	apply_width_integer_pad(t_printf_part *part, char **sp, int l, int w);

/*
** %a %A dependencies.
*/
char	*ft_build_unnormalized(double nbr, t_printf_part *part);
char	*ft_build_normalized(double nbr, t_printf_part *part);
void	round_mantissa_b16(char **ptr, int pre, int *int_part_two);

/*
** %S dependencies.
*/
size_t	npnt_len(char *str, t_printf_part *part, int p);
void	npnt_cat(char **ret, char src, char *input, int *color_status);

/*
** Buffer.
*/
int		ptf_buffer_infos(char *arg1, int arg2);
int		ptf_cols_concat_string(char **ret, t_list *l, int *cols, int n);
size_t	ptf_calc_real_content_size(t_list *lst);

/*
** shity debug
*/
# include <stdio.h>
typedef unsigned char *byte_pointer;
void	inspect_part(t_printf_part *part);
void	showbits(byte_pointer x, int bits, int highlightmin, int highlightmax);

#endif
