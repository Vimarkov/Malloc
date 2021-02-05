/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_fontions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:21:26 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/26 21:14:02 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void		print_supp(size_t *total, size_t block_size)
{
	*total += block_size;
	ft_putstr(" : ");
	ft_putnbr(block_size);
	ft_putendl(" octets");
}

void		print_supp1(size_t total)
{
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" octets");
}

void		*supp_malloc(void **point, t_zone **zone, size_t size)
{
	*zone = creat_zone_page(size);
	*point = *zone;
	return (point);
}

int			supp_malloc1(void **point, t_zone **zone, size_t size,
						t_block **block)
{
	int bi;

	bi = 0;
	*block = last_block(*zone, size, &bi);
	if (bi == 1)
	{
		*point = *block;
		return (1);
	}
	return (0);
}

void		set_null(t_block **block, void **point)
{
	*block = NULL;
	*point = NULL;
}
