/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_fontions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:02:47 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/26 22:33:47 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*big_realloc(void *ret, size_t size, void **ptr)
{
	ret = malloc(size);
	ft_strncpy(ret, (char*)*ptr, size);
	free(*ptr);
	return (ret);
}

void		*small(int *av, size_t *siz, void **ptr, size_t size)
{
	free(*ptr);
	*av = 0;
	*siz = size;
	return (*ptr);
}

void		*failed_malloc(void **ptr, size_t size, size_t *i, t_zone **zone)
{
	void	*ret;

	ret = NULL;
	*i = 0;
	*zone = g_zone;
	if (size <= 0)
		free(*ptr);
	return (ret);
}
