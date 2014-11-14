/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:29:36 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/14 11:45:59 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_ls.h>
#include <stdio.h>

/*
** 'ls_free_args' non-NULL call saves the pointer. NULL call frees it.
*/

void	ls_free_args(void *args)
{
	static t_lsargs	*save = NULL;

	if (save == NULL)
	{
		if (args == NULL)
			perror("'ls_free_args' was about to free a NULL pointer");
		else
			save = (t_lsargs*)args;	
	}
	else
	{
		if (args == NULL)
			free((void*)save);
		else
			perror("'ls_free_args' 'save' already exists");
	}
}
