/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_displays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:11:13 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/16 16:00:40 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_pf_putc(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_pf_puts(char const *s, int fd)
{
	int	r;

	r = 0;
	while (*s != '\0')
	{
		ft_pf_putc(*s, fd);
		s++;
		r++;
	}
	return (r);
}

int		ft_pf_putn(int n, int fd, int r)
{
	if (n == -2147483648)
		r = ft_pf_puts("-2147483648", fd);
	else if (n < 0)
	{
		r = r + ft_pf_putc('-', fd);
		ft_pf_putn(-n, fd, r);
	}
	else if (n >= 10)
	{
		ft_pf_putn(n / 10, fd, r);
		r = r + ft_pf_putc(n % 10 + '0', fd);
	}
	else
		r = r + ft_pf_putc(n + '0', fd);
	return (r);
}
