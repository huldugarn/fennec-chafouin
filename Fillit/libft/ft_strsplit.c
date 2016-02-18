/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:02:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/09 15:38:48 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	segment_counter(char const *s, char c)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				i;
	int				j;
	int				next;

	i = 0;
	next = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * segment_counter(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tab[next++] = ft_strndup(s + j, i - j);
	}
	tab[next] = NULL;
	return (tab);
}
