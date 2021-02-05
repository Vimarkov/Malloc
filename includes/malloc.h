/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:42:43 by vimarkov          #+#    #+#             */
/*   Updated: 2019/09/26 22:55:59 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include "../libft/includes/libft.h"

# define TINY_Z	64
# define SMALL_Z	1024
# define LARGE_Z	2

# define TINY_S (3 * 4096)
# define SMALL_S (27 * 4096)

typedef struct			s_zone
{
	struct s_zone		*next;
	size_t				type;
	struct s_block		*block;
	int					rem;
	int					av;
}						t_zone;

typedef struct			s_block
{
	size_t				size;
	int					av;
	struct s_block		*next;
}						t_block;

t_zone		*g_zone;
int			g_add;

void					*malloc(size_t size);
void					*start_glo(void);
void					set_glo(void *zone);
t_zone					*new_zone(t_zone *zone);
t_zone					*check_zone(t_zone *zone, size_t size);
void					add_zone(t_zone *zone);
void					print_list(void);
void					print_list1(t_zone *zone);
t_block					*last_block(t_zone *zone, int size, int *bi);
t_zone					*alloc_block(size_t size, t_zone *zone,
							t_block *block);
void					*add_block(t_zone *zone, t_block *block, size_t size,
							void *point);
size_t					chain_block(t_zone *zone, size_t perf);
void					print_supp(size_t *total, size_t block_size);
void					print_supp1(size_t total);
void					*supp_malloc(void **point, t_zone **zone, size_t size);
int						supp_malloc1(void **point, t_zone **zone, size_t size,
							t_block **block);
void					creat_malloc(void *point, t_zone *zone, size_t size);
t_zone					*creat_zone_page(size_t size);
void					show_alloc_mem();
void					*realloc(void *ptr, size_t size);
void					free(void *ptr);
void					set_null(t_block **block, void **point);
void					*big_realloc(void *ret, size_t size, void **ptr);
void					*small(int *av, size_t *siz, void **ptr, size_t size);
void					*failed_malloc(void **ptr, size_t size, size_t *i,
							t_zone **zone);
#endif
