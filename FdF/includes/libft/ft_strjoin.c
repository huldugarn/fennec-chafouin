/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:23:21 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/01 11:30:41 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s_join;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s_join = ft_strnew(len);
	i = 0;
	j = 0;
	if (s_join)
	{
		while (s1[j] != '\0')
			s_join[i++] = s1[j++];
		j = 0;
		while (s2[j] != '\0')
			s_join[i++] = s2[j++];
		s_join[i] = '\0';
		return (s_join);
	}
	else
		return (NULL);
}
