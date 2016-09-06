/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:51:27 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/29 15:56:53 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	if (!(str = (char *)ft_strnew(sizeof(char) * n)))
		return (NULL);
	else
	{
		str = ft_strncpy(str, s, n);
		str[n] = '\0';
	}
	return (str);
}
