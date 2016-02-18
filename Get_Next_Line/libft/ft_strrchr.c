/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:06:22 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/19 16:02:42 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	const char	*f;

	f = NULL;
	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while ((p = ft_strchr(s, c)) != NULL)
	{
		f = p;
		s = p + 1;
	}
	return ((char *)f);
}
