/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:42:39 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/19 23:46:25 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_zone		*check_zone(t_zone *zone, size_t size)
{
	int value;

	value = size;
	while (zone && (size > SMALL_Z ||
		size > zone->type || zone->rem < value))
	{
		if (zone && (size > SMALL_Z && zone->av == 1))
		{
			if (MAP_FAILED == (zone = mmap(zone + sizeof(t_zone), size,
				PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0)))
				return (NULL);
		}
		zone = zone->next;
	}
	return (zone);
}

void		add_zone(t_zone *zone)
{
	t_zone *new;

	new = g_zone;
	while (new && new->next)
		new = new->next;
	if (new)
		new->next = zone;
	else
		g_zone = zone;
}

void		print_list(void)
{
	t_zone		*zone;
	t_block		*block;
	int			i;

	zone = g_zone;
	while (zone)
	{
		i = 0;
		block = zone->block;
		printf("zone type = %zu\n", zone->type);
		while (block)
		{
			i++;
			printf("block size = %lu\n", block->size);
			block = block->next;
		}
		zone = zone->next;
	}
}
