/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 08:50:11 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/14 11:37:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

/*
** Version 1 of ft_error.
*/

void	ft_error_malloc(void);
void	ft_error_illegal_op(int fi, char o, char *fl, void (*f)(void *p));
void	ft_error_unknown(void);

#endif
