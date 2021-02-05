/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:34:19 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/26 22:34:21 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "string.h"

size_t		get_size_page(size_t size, size_t *rem, int *type)
{
	size_t final_nb;
	size_t lenght;

	final_nb = 0;
	lenght = size;
	if (lenght > SMALL_Z)
	{
		*rem = 0;
		final_nb = lenght + sizeof(t_zone) + sizeof(t_block);
		*type = LARGE_Z;
	}
	else if (lenght > TINY_Z)
	{
		*rem = SMALL_S;
		final_nb = SMALL_S;
		*type = SMALL_Z;
	}
	else
	{
		*rem = TINY_S;
		final_nb = TINY_S + sizeof(t_zone);
		*type = TINY_Z;
	}
	return (final_nb);
}

t_zone		*creat_zone_page(size_t size)
{
	size_t	final_nb;
	t_zone	*new_zone;
	size_t	rem;
	int		type;

	final_nb = get_size_page(size, &rem, &type);
	if (MAP_FAILED == (new_zone = mmap(NULL, final_nb,
		PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0)))
		return (NULL);
	new_zone->next = NULL;
	new_zone->rem = rem;
	new_zone->type = type;
	new_zone->block = NULL;
	add_zone(new_zone);
	return (new_zone);
}

void		*malloc(size_t size)
{
	t_zone	*zone;
	t_block *block;
	void	*point;
	size_t	perf;
	int		bi;

	bi = 0;
	perf = 0;
	set_null(&block, &point);
	if (size == 0)
		return (NULL);
	zone = check_zone(g_zone, size);
	if (!zone)
		supp_malloc(&point, &zone, size);
	else
	{
		if (supp_malloc1(&point, &zone, size, &block) == 1)
			return (point + sizeof(t_block));
	}
	perf = chain_block(zone, perf);
	if (zone->type != LARGE_Z)
		zone->rem -= (size + sizeof(t_block));
	point = zone;
	point = add_block(zone, block, size, point + sizeof(t_zone) + perf);
	return (point + sizeof(t_block));
}
