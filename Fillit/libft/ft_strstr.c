/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <rle-corr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 16:23:08 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/12 14:12:52 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	ap;
	int rp;

	ap = 0;
	rp = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[ap] != '\0')
	{
		while (s1[ap] == s2[rp] && s2[rp] != '\0')
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
