/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 07:11:06 by viclucas          #+#    #+#             */
/*   Updated: 2019/07/08 07:56:51 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendls(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		ft_putendl(s1);
	if (s2)
		ft_putendl(s2);
	if (s3)
		ft_putendl(s3);
	if (s4)
		ft_putendl(s4);
}
