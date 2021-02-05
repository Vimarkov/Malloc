/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 00:01:56 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/19 23:42:53 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			hex_conv(size_t div)
{
	char start;

	if (div == 10)
	{
		ft_putchar('A');
		return (0);
	}
	if (div > 10)
	{
		start = 'A';
		while (div > 10)
		{
			start++;
			div--;
		}
		ft_putchar(start);
	}
	else
		ft_putnbr(div);
	return (0);
}

int			get_div(size_t add)
{
	size_t rest;

	if (add)
	{
		rest = add % 16;
		add = add / 16;
	}
	else
		return (0);
	get_div(add);
	hex_conv(rest);
	return (0);
}

void		print_alloc(t_zone *zone, size_t add)
{
	if (zone->type == TINY_Z)
		write(1, "TINY : 0x", 9);
	if (zone->type == SMALL_Z)
		write(1, "SMALL : 0x", 10);
	if (zone->type == LARGE_Z)
		write(1, "LARGE : 0x", 10);
	get_div(add);
	ft_putchar('\n');
}

void		print_mem(size_t *add, t_block *block)
{
	*add += (size_t)sizeof(t_block);
	ft_putstr("0x");
	get_div(*add);
	ft_putstr(" - ");
	ft_putstr("0x");
	*add += block->size;
	get_div(*add);
}

void		show_alloc_mem(void)
{
	t_zone		*zone;
	t_block		*block;
	size_t		add;
	size_t		total;

	total = 0;
	zone = g_zone;
	while (zone)
	{
		if (!zone->av)
		{
			add = (size_t)zone;
			block = zone->block;
			print_alloc(zone, add);
			add += sizeof(t_zone);
			while (block)
			{
				print_mem(&add, block);
				print_supp(&total, block->size);
				block = block->next;
			}
		}
		zone = zone->next;
	}
	print_supp1(total);
}
