/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:12:11 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/05 11:24:12 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*s_mapi;
	unsigned int		i;

	s_mapi = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	i = 0;
	if (s_mapi)
	{
		while (s[i] != '\0')
		{
			s_mapi[i] = f(i, s[i]);
			i++;
		}
		s_mapi[i] = '\0';
		return (s_mapi);
	}
	else
		return (NULL);
}
