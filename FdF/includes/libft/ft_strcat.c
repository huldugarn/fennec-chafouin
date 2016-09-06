/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:51:16 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/15 16:35:26 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int l;

	i = 0;
	l = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[l + i] = s2[i];
		i++;
	}
	s1[l + i] = '\0';
	return (s1);
}
