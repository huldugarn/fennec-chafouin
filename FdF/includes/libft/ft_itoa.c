/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:06:09 by rle-corr          #+#    #+#             */
/*   Updated: 2016/06/07 14:59:45 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		s[1] = '\0';
		s = ft_strjoin(s, ft_itoa(-n));
	}
	else if (n >= 10)
		s = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else
	{
		s[0] = n + '0';
		s[1] = '\0';
	}
	return (s);
}

char		*ft_itoa_base(int value, int base)
{
	char	*s;
	char	*c;
	int		l;
	int		v;

	if (base == 0)
		return (NULL);
	if (value < 0)
		return (s = ft_strjoin("-\0", ft_itoa_base(-value, base)));
	while ((v = value) != 0)
	{
		v /= base;
		l == (int)NULL ? l = 1 : ++l;
	}
	if (!(s = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	s[l--] = '\0';
	c = "0123456789ABCDEF\0";
	while (value != 0)
	{
		s[l] = c[value % base];
		value /= base;
		--l;
	}
	return (s);
}
