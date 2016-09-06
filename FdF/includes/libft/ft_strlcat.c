/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 12:09:38 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/19 15:41:22 by rle-corr         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
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
