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

char					*ft_ullitoa_base(unsigned long long value, int base)
{
	char				*s;
	char				*c;
	int					l;
	unsigned long long	v;

	if (base < 2 || base > 16 || value == 0)
		return (value == 0 ? ft_strdup("0") : NULL);
	v = value;
	l = 1;
	while ((v /= base) != 0)
		++l;
	if (!(s = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	s[l--] = '\0';
	c = "0123456789abcdef\0";
	while (value != 0)
	{
		s[l] = c[value % base];
		value /= base;
		--l;
	}
	return (s);
}

char					*ft_llitoa_base(long long n, int base)
{
	unsigned long long	u_n;

	u_n = n < 0 ? n * -1 : n;
	if (n < 0 && base == 10)
		return (ft_strjoin("-\0", ft_ullitoa_base(u_n, base)));
	return (ft_ullitoa_base(u_n, base));
}

char					*ft_itoa_base(int n, int base)
{
	long long			lln;

	lln = n;
	return (ft_llitoa_base(lln, base));
}

char					*ft_itoa(int n)
{
	long long			lln;

	lln = n;
	return (ft_llitoa_base(lln, 10));
}
