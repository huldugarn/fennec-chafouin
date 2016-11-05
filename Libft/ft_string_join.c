/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 11:02:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/29 11:02:50 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strnjoin
**	Append [len] characters of string [s2] to string [s1] in a newly allocated
**	[s_join] string.
*/

char		*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	int		length;
	char	*s_join;
	char	*p;

	length = ft_strlen(s1) + ++n;
	s_join = ft_strnew(length);
	p = s_join;
	if (s_join)
	{
		while (*s1)
			*s_join++ = *s1++;
		while (*s2 && --n > 0)
			*s_join++ = *s2++;
		return (s_join - (s_join - p));
	}
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s_join;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s_join = ft_strnew(len);
	i = 0;
	j = 0;
	if (s_join)
	{
		while (s1[j] != '\0')
			s_join[i++] = s1[j++];
		j = 0;
		while (s2[j] != '\0')
			s_join[i++] = s2[j++];
		s_join[i] = '\0';
		return (s_join);
	}
	else
		return (NULL);
}

wchar_t		*ft_wstrnjoin(wchar_t const *wstr1, wchar_t const *wstr2, size_t n)
{
	wchar_t	*wstr;
	size_t	length;
	int		a;
	int		r;

	length = ft_wstrlen(wstr1) + ++n;
	if (!(wstr = ft_wstrnew(length)))
		return (NULL);
	a = 0;
	r = 0;
	while (wstr1[r] != L'\0')
	{
		wstr[a] = wstr1[r];
		++a;
		++r;
	}
	r = 0;
	while (wstr2[r] != L'\0')
	{
		wstr[a] = wstr2[r];
		++a;
		++r;
	}
	wstr[a] = L'\0';
	return (wstr);
}

wchar_t		*ft_wstrjoin(wchar_t const *wstr1, wchar_t const *wstr2)
{
	return (ft_wstrnjoin(wstr1, wstr2, ft_wstrlen(wstr2)));
}
