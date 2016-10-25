/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <rle-corr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 17:39:32 by rle-corr          #+#    #+#             */
/*   Updated: 2015/11/28 15:43:39 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int		l;

	l = 0;
	while (str[l] != '\0')
		++l;
	return (l);
}

int			ft_wchar_width(wchar_t wchar)
{
	int		width;
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
	free(binlen);
	return (width);
}

int			ft_wstrlen(wchar_t *wstr)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (wstr[i] != L'\0')
	{
		l = l + ft_wchar_width(wstr[i]);
		++i;
	}
	return (l)
}
