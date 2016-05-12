/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_displays1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 11:55:20 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/12 11:55:33 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		pfpc(char c, int fd, int tc)
{
	char a;

	a = c;
	if (tc == 1 && (c >= 'a' && c <= 'z'))
	{
		a = c - 32;
		write(fd, &a, 1);
	}
	else if (tc == 2 && (c >= 'A' && c <= 'Z'))
	{
		a = c + 32;
		write(fd, &a,1);
	}
	else
		write(fd, &a, 1);
	return (1);
}

int		pfps(char const *s, int fd, int tc)
{
	int	r;

	r = 0;
	while (*s != '\0')
	{
		pfpc(*s, fd, tc);
		s++;
		r++;
	}
	return (r);
}

int		pfpn(int n, int fd, int r)
{
	if (n == -2147483648)
		r = pfps("-2147483648", fd, 0);
	else if (n < 0)
	{
		r = r + pfpc('-', fd, 0);
		pfpn(-n, fd, r);
	}
	else if (n >= 10)
	{
		r = r + pfpn(n / 10, fd, r);
		r = r + pfpc(n % 10 + '0', fd, 0);
	}
	else
		r = r + pfpc(n + '0', fd, 0);
	return (r);
}
