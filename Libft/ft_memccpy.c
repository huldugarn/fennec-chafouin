/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:22:45 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/09 13:17:19 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dst_p;
	char	*src_p;

	i = 0;
	dst_p = (char *)dst;
	src_p = (char *)src;
	while (i < n)
	{
		dst_p[i] = src_p[i];
		if ((unsigned char)src_p[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
