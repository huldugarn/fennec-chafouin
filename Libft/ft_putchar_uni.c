/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:40:36 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/17 10:49:51 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar(char c, int fd)
{
	char	**c_uni;
	int		i;

	if ((unsigned int)c <= 127)
		write(fd, &c, 1);
	else
	{
		c_uni = ft_unicode((unsigned int)c);
		i = 0;
		while (c_uni[i] != 0)
		{
			write(fd, &(ft_atoi(c_uni[i])), 1);
			i++;
		}
	}
}
