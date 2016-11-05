/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_concatenate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 11:27:39 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/29 11:27:44 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	---- Documentation --------------------------------------------------------
**  strlcat mecanism found on :
**  www.opensource.apple.com/source/apache_mod_php/apache_mod_php-4.3/php/main
**  ---- Variables ------------------------------------------------------------
**  Pointers on char [d] and [s] are declared to be used as cursors on strings;
**  Their values set respectively to point on [dst] and [src].
**	Variable [a] is declared and its value is initialized at the [size] one.
**	[a] is meant to represent the amount of bytes available for concatenation.
**	Variable [l] is declared and is meant to store the concatenated length of
**	[dst] : the length before its fisrt occurencce of NUL and size compliant.
**	---- Instructions ---------------------------------------------------------
**	The first [while] loop increment our [d] cursor as long as
**	- decremented amount of bytes available for concatenation don't reach zero;
**	- cursor [d] doesn't point on the [\0] value in string [dst].
**	Thus, length [l] of [dst] is stored as the pointers substraction [d]-[dst],
**	and [a] is reset as the [size] minus [l].
**	There will be no more than [a] bytes of [src] appended to [dst] as more
**	bytes wouldn't fit in the allocated memory for [dst].
**	Next [if] condition makes sure strlcat returns ? if no bytes for
**	concatenation are available.
**	Second [while] loop do the concatenation on incremented [d] as long as
**	- incremented cursor on [src] doesn't reach [\0];
**	- decremented amount of available bytes [a] doesn't reach the one byte left
**	  for the terminating NUL.
**	The last position of cursor [d] is set to value [\0];
**	Finally, added lengths of [dst] and effectively concatenated [src]
**	is returned.
**	---------------------------------------------------------------------------
*/

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		a;
	size_t		l;

	d = dst;
	s = src;
	a = size;
	while (*d != '\0' && a-- != 0)
		d++;
	l = d - dst;
	a = size - l;
	if (a == 0)
		return (l + ft_strlen(s));
	while (*s != '\0')
	{
		if (a != 1)
		{
			*d++ = *s;
			a--;
		}
		s++;
	}
	*d = '\0';
	return (l + (s - src));
}

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		l;

	i = 0;
	l = ft_strlen(s1);
	while (i < n)
	{
		if (s2[i] == '\0')
			break ;
		s1[l + i] = s2[i];
		i++;
	}
	s1[l + i] = '\0';
	return (s1);
}

char			*ft_strcat(char *s1, const char *s2)
{
	int			i;
	int			l;

	i = 0;
	l = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[l + i] = s2[i];
		++i;
	}
	s1[l + i] = '\0';
	return (s1);
}

wchar_t			*ft_wstrncat(wchar_t *dst, wchar_t *src, size_t n)
{
	size_t		i;
	size_t		l;

	i = 0;
	l = ft_wstrlen(dst);
	while (i < n)
	{
		if (src[i] == L'\0')
			break ;
		dst[l + i] = src[i];
		++i;
	}
	src[l + i] = L'\0';
	return (dst);
}

wchar_t			*ft_wstrcat(wchar_t *dst, wchar_t *src)
{
	return (ft_wstrncat(dst, src, ft_wstrlen(src)));
}
