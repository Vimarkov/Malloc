/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:34:00 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/26 22:34:06 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_block *block;
	void	*ret;
	size_t	i;

	if (ptr == 0)
		return ((ret = malloc(size)));
	ret = failed_malloc(&ptr, size, &i, &zone);
	while (zone)
	{
		block = zone->block;
		while (block)
		{
			if ((size_t)block + sizeof(t_block) == (size_t)ptr)
			{
				if (size > LARGE_Z)
					return (ret = big_realloc(ret, size, &ptr));
				else
					return (ptr = small(&block->av, &block->size, &ptr, size));
			}
			block = block->next;
		}
		zone = zone->next;
	}
	return (NULL);
}
