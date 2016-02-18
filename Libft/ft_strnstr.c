/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:11:47 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/29 14:21:16 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	ap;
	size_t	rp;

	ap = 0;
	rp = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[ap] != '\0' && ap < n)
	{
		while (s1[ap] == s2[rp] && ap < n)
		{
			rp++;
			ap++;
			if (s2[rp] == '\0')
				return ((char *)s1 + (ap - rp));
		}
		ap = ap - rp;
		rp = 0;
		ap++;
	}
	return (0);
}
