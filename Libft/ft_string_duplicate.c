/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:34:53 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/27 14:34:59 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	if (!(dup = (char *)ft_strnew(sizeof(char) * n)))
		return (NULL);
	dup = ft_strncpy(dup, str, n);
	dup[n] = '\0';
	return (dup);
}

char	*ft_strdup(const char *str)
{
	return (ft_strndup(str, ft_strlen(str)));
}

wchar_t	*ft_wstrndup(const wchar_t *wstr, size_t n)
{
	wchar_t	*wdup;

	if (!(wdup = (wchar_t*)ft_wstrnew(sizeof(wchar_t) * n)))
		return (NULL);
	wdup = ft_wstrncpy(wdup, wstr, n);
	wdup[n] = L'\0';
	return (wdup);
}

wchar_t	*ft_wstrdup(const wchar_t *wstr)
{
	return (ft_wstrndup(wstr, ft_wstrlen(wstr)));
}
