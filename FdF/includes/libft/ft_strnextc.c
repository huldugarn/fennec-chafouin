/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnextc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:52:25 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/26 15:52:31 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnextc(unsigned int i, char const *s, char c)
{
	unsigned int	t;

	t = i;
	while (s[i] != '\0')
	{
		if (i == t || s[i] == c || (s[i] != c && s[i - 1] != c))
			i++;
		else
			return (i);
	}
	return (-1);
}
