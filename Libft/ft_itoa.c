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

char					*ft_itoa(int n)
{
	char				*s;

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

char					*ft_itoa_base(int value, int base)
{
	char				*s;
	char				*c;
	int					l;
	int					v;

	if (base == 0)
		return (NULL);
	if ((v = value) < 0)
		return (s = ft_strjoin("-\0", ft_itoa_base(-value, base)));
	while (v != 0)
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

char					*ft_llitoa(long long n)
{
	char				*s;

	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -9223372036854775807)
		return ("-9223372036854775807");
	if (n < 0)
	{
		s[0] = '-';
		s[1] = '\0';
		s = ft_strjoin(s, ft_llitoa(-n));
	}
	else if (n >= 10)
		s = ft_strjoin(ft_llitoa(n / 10), ft_llitoa(n % 10));
	else
	{
		s[0] = n + '0';
		s[1] = '\0';
	}
	return (s);
}

char					*ft_ullitoa(unsigned long long n)
{
	char				*s;

	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n >= 10)
		s = ft_strjoin(ft_ullitoa(n / 10), ft_ullitoa(n % 10));
	else
	{
		s[0] = n + '0';
		s[1] = '\0';
	}
	return (s);
}

char					*ft_ullitoa_base(unsigned long long value, int base)
{
	char				*s;
	char				*c;
	int					l;
	unsigned long long	v;

	if (base == 0)
		return (NULL);
	v = value;
	l = 0;
	while (v != 0)
	{
		v /= base;
		l == 0 ? l = 1 : ++l;
		printf("%i\n", l);
	}
	if (!(s = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	s[l--] = '\0';
	c = "0123456789abcdef\0";
	while (value != 0)
	{
		printf("s[%i] = %c, value = %llu\n", l, c[value % base], value);
		s[l] = c[value % base];
		value /= base;
		--l;
	}
	return (s);
}
