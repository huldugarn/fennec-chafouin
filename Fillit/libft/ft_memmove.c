/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:41:33 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/31 18:09:26 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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
