/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:54:54 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/09 13:44:22 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
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
