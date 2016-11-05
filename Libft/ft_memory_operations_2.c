/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:41:28 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/27 13:41:50 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		++i;
	}
	return (dst);
}

/*
**	---	Excerpt form BSD Library Function Manual - MEMCCPY(3) ------------------
**	The memccpy() function copies bytes from string src to string dst.
**	If the character c (as converted to an unsigned char) occurs in the string
**	src, the copy stops and a pointer to the byte after the copy of c in the
**	string dst is returned.
**	Otherwise, n bytes are copied, and a NULL pointer is returned.
**	The source and destination strings should not overlap, as the behavior is
**	undefined.
*/

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*dst_p;
	char			*src_p;

	i = 0;
	dst_p = (char *)dst;
	src_p = (char *)src;
	while (i < n)
	{
		dst_p[i] = src_p[i];
		if ((unsigned char)src_p[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		++i;
	}
	return (NULL);
}

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (!len)
		return (dst);
	if ((size_t)(dst_p - src_p) >= len)
		return (ft_memcpy(dst, src, len));
	src_p += len;
	dst_p += len;
	while (len--)
		*--dst_p = *--src_p;
	return (dst);
}

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*p;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (p = (void *)&s[i]);
		else
			++i;
	}
	return (NULL);
}

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			++i;
		else
			return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
	}
	return (0);
}
