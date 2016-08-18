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

char		**ft_unicode(unsigned int n)
{
	char	*b;
	int		l;

	b = ft_btoa(ft_itob(n));
	l = ft_strlen(b);
	if (l < 12)
		return (ft_unimask2(b, l));
	if (l >= 12 && l < 16)
		return (ft_unimask3(b, l));
	if (l >= 16)
		return (ft_unimask4(b, l));
	return (NULL);
}

char		**ft_unimask2(char *b, int l)
{
	char	*tab[2];
	char	**p;
	int		i;
	int		j;

	tab[0] = "11000000";
	tab[1] = "10000000";
	i = 1;
	j = 7;
	while (l > 0)
	{
		if (j < 2)
		{
			j = 7;
			i--;
		}
		tab[i][j--] = b[l--];
	}
	p = tab;
	return (p);
}

char		**ft_unimask3(char *b, int l)
{
	char	*tab[3];
	char	**p;
	int		i;
	int		j;

	tab[0] = "11100000";
	tab[1] = "10000000";
	tab[2] = "10000000";
	i = 2;
	j = 7;
	while (l > 0)
	{
		if (j < 2)
		{
			j = 7;
			i--;
		}
		tab[i][j--] = b[l--];
	}
	p = tab;
	return (p);
}

char		**ft_unimask4(char *b, int l)
{
	char	*tab[4];
	char	**p;
	int		i;
	int		j;

	tab[0] = "11110000";
	tab[1] = "10000000";
	tab[2] = "10000000";
	tab[3] = "10000000";
	i = 3;
	j = 7;
	while (l > 0)
	{
		if (j < 2)
		{
			j = 7;
			i--;
		}
		tab[i][j--] = b[l--];
	}
	p = tab;
	return (p);
}
