/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:34:27 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/26 22:34:29 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone		*small_free(t_zone *zone, t_block *block, void *ptr)
{
	if (zone)
	{
		while (block)
		{
			if ((size_t)block + sizeof(t_block) == (size_t)ptr)
			{
				block->av = 1;
				block->size = 0;
			}
			block = block->next;
		}
		zone = zone->next;
	}
	return (zone);
}

void		free(void *ptr)
{
	t_zone	*zone;
	t_block *block;
	t_zone	*new;

	new = NULL;
	zone = g_zone;
	while (zone)
	{
		block = zone->block;
		if (zone && zone->type == LARGE_Z)
		{
			if ((size_t)block + sizeof(t_block) == (size_t)ptr)
			{
				munmap(zone + sizeof(t_zone) + sizeof(t_block), block->size);
				zone->av = 1;
				break ;
			}
		}
		zone = small_free(zone, block, ptr);
	}
}
