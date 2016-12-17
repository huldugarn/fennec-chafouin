/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:46:43 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/24 17:42:27 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	nombre de bits : (attention, power doit gerer le resultat en long)
**	while (ft_power(2, i++) < n);
*/

char		**ft_unicode(unsigned long long int n)
{
	char	*b;
	int		l;

	b = ft_ullitoa_base(n, 2);
	l = ft_strlen(b);
	if (l < 12)
		return (ft_unimask2(b, l));
	if (l < 17)
		return (ft_unimask3(b, l));
	if (l < 22)
		return (ft_unimask4(b, l));
	return (NULL);
}

char		**ft_unimask2(char *b, int l)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * 3)))
		return (NULL);
	tab[0] = ft_strdup("11000000");
	tab[1] = ft_strdup("10000000");
	tab[2] = NULL;
	i = 1;
	j = 7;
	while (l > 0)
	{
		if (j < 2)
		{
			j = 7;
			i--;
		}
		tab[i][j--] = b[--l];
	}
	return (tab);
}

char		**ft_unimask3(char *b, int l)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * 4)))
		return (NULL);
	tab[0] = ft_strdup("11100000\0");
	tab[1] = ft_strdup("10000000\0");
	tab[2] = ft_strdup("10000000\0");
	tab[3] = NULL;
	i = 2;
	j = 7;
	while (l > 0)
	{
		if (j < 2)
		{
			j = 7;
			--i;
		}
		tab[i][j--] = b[--l];
	}
	return (tab);
}

char		**ft_unimask4(char *b, int l)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * 5)))
		return (NULL);
	tab[0] = ft_strdup("11110000");
	tab[1] = ft_strdup("10000000");
	tab[2] = ft_strdup("10000000");
	tab[3] = ft_strdup("10000000");
	tab[4] = NULL;
	i = 3;
	j = 7;
	while (l > 0)
	{
		if (j < 2)
		{
			j = 7;
			--i;
		}
		tab[i][j--] = b[--l];
	}
	return (tab);
}
