/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:32:31 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/27 14:32:38 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dst[index] = src[index];
		index++;
	}
	while (dst[index] != '\0' && index < n)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}

char		*ft_strcpy(char *dst, const char *src)
{
	return (ft_strncpy(dst, src, ft_strlen(src)));
}

wchar_t		*ft_wstrncpy(wchar_t *cpy, const wchar_t *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] != L'\0' && i < n)
	{
		cpy[i] = str[i];
		++i;
	}
	while (cpy[i] != L'\0' && i < n)
	{
		cpy[i] = L'\0';
		++i;
	}
	return (cpy);
}

wchar_t		*ft_wstrcpy(wchar_t *cpy, const wchar_t *str)
{
	return (ft_wstrncpy(cpy, str, ft_wstrlen(str)));
}
