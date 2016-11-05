/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:12:41 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/27 14:12:46 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

wchar_t		*ft_wstrnew(size_t size)
{
	return ((wchar_t*)ft_memalloc(sizeof(wchar_t) * (size + 1)));
}

size_t		ft_strlen(const char *str)
{
	int		l;

	l = 0;
	while (str[l] != '\0')
		++l;
	return (l);
}

size_t		ft_wchar_width(wchar_t wchar)
{
	size_t	width;
	char	*binary;
	int		binlen;

	width = 0;
	binary = ft_ullitoa_base((unsigned long long int)wchar, 2);
	binlen = ft_strlen(binary);
	if (binlen < 8)
		width = 1;
	else if (binlen < 12)
		width = 2;
	else if (binlen < 17)
		width = 3;
	else
		width = 4;
	free(&binlen);
	return (width);
}

size_t		ft_wstrlen(const wchar_t *wstr)
{
	size_t	l;
	int		i;

	l = 0;
	i = 0;
	while (wstr[i] != L'\0')
	{
		l = l + ft_wchar_width(wstr[i]);
		++i;
	}
	return (l);
}
