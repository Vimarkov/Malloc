/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:41:53 by viclucas          #+#    #+#             */
/*   Updated: 2019/08/01 10:08:55 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	*store(int nb)
{
	size_t		y;
	size_t		i;
	char		*base;
	char		*ret;

	base = "0123456789abcdef";
	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * 17)))
		return (NULL);
	ret[i++] = '0';
	while (nb >= 16)
	{
		nb /= 16;
		y = nb % 16;
		ret[i++] = base[y];
	}
	ret[i] = '\0';
	return (ret);
}

void		hexa_64(int nb)
{
	int			i;
	char		*ret;

	i = 0;
	if (nb < 16)
	{
		while (i++ < NM_OTOOL_PADDING)
			ft_putchar(' ');
		return ;
	}
	if (!(ret = store(nb)))
		return ;
	ft_putstr("00000001");
	i = 8 - (ft_strlen(ret) + 1);
	while (i--)
		ft_putchar('0');
	i = 0;
	while (ret[i + 1])
		i++;
	while (i >= 0)
	{
		ft_putchar(ret[i]);
		i--;
	}
}
