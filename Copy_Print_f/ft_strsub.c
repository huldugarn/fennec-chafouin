/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:07:54 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/05 11:31:21 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_sub;
	size_t	i;

	s_sub = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (s_sub)
	{
		while (i < len)
			s_sub[i++] = s[start++];
		s_sub[i] = '\0';
		return (s_sub);
	}
	else
		return (NULL);
}
