/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:17:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/23 16:16:04 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strnjoin
**	Append [len] characters of string [s2] to string [s1] in a newly allocated
**	[s_join] string.
*/

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	int		n;
	char	*s_join;
	char	*p;

	n = ft_strlen(s1) + len++;
	s_join = ft_strnew(n);
	p = s_join;
	if (s_join)
	{
		while (*s1)
			*s_join++ = *s1++;
		while (*s2 && --len > 0)
			*s_join++ = *s2++;
		return (s_join - (s_join - p));
	}
	return (NULL);
}
