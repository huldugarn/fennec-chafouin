/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:44:24 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/15 16:39:32 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memdel(void **byte_adress)
{
	free(*byte_adress);
	*byte_adress = NULL;
}

void		*ft_memset(void *byte, int c, size_t length)
{
	while (length > 0)
	{
		--length;
		((char *)byte)[length] = (unsigned char)c;
	}
	return (byte);
}

void		ft_bzero(void *byte, size_t length)
{
	byte = ft_memset(byte, 0, length);
}

void		*ft_memalloc(size_t size)
{
	size_t	*locus;

	if (size > 2147483647)
		return (NULL);
	locus = (void *)malloc(size);
	if (locus == NULL)
		return (NULL);
	ft_bzero(locus, size);
	return (locus);
}
