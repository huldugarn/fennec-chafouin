/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:56:16 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/11 14:56:19 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, 1);
}

void		ft_putwchar_fd(wchar_t c, int fd)
{
	char	**c_uni;
	int		i;
	int		r;

	if ((unsigned long long int)c <= 127)
		write(fd, &c, 1);
	else
	{
		c_uni = ft_unicode((unsigned long long int)c);
		i = 0;
		while (c_uni[i] != 0)
		{
			r = ft_atoi_base(c_uni[i], 10);
			write(fd, &(r), 1);
			i++;
		}
	}
}
