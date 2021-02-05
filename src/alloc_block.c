/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:57:38 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/26 22:34:57 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		chain_block(t_zone *zone, size_t perf)
{
	t_block *lenght;

	lenght = zone->block;
	while (lenght && lenght->next)
	{
		perf += lenght->size + sizeof(t_block);
		lenght = lenght->next;
	}
	if (zone->block)
		perf += lenght->size + sizeof(t_block);
	return (perf);
}

void		*add_block(t_zone *zone, t_block *block, size_t size, void *point)
{
	if (block)
		block->next = point;
	else
		zone->block = point;
	((t_block*)point)->next = NULL;
	((t_block*)point)->size = size;
	((t_block*)point)->av = 0;
	return (point);
}

t_block		*last_block(t_zone *zone, int size, int *bi)
{
	t_block *block;

	block = zone->block;
	while (block)
	{
		if (block->av == 1)
		{
			block->av = 0;
			block->size = size;
			*bi = 1;
			return (block);
		}
		block = block->next;
	}
	block = zone->block;
	while (block && block->next)
		block = block->next;
	return (block);
}
