/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:56:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/05 11:25:53 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_map;
	int		i;

	s_map = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	i = 0;
	if (s_map)
	{
		while (s[i] != '\0')
		{
			s_map[i] = f(s[i]);
			i++;
		}
		s_map[i] = '\0';
		return (s_map);
	}
	else
		return (NULL);
}
