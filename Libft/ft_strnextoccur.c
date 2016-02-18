/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnextoccur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:46:31 by rle-corr          #+#    #+#             */
/*   Updated: 2015/12/03 16:45:59 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnextoccur(unsigned int i, char const *s, char c)
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
