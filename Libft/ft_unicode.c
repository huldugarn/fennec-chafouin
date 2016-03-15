/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:07:15 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/15 17:26:21 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_itob(unsigned int i)
{
	t_list	*bit;
	t_list	**binary;

	bit = NULL;
	binary = b;
	while (i > 0)
	{
		ft_lstadd(binary, ft_lstnew(i % 2, 1));
		i = i/2;
	}
	return (binary);
}

char		*ft_btoa(t_list **binary)
{
	t_list	*cursor;
	int		l;
	char	*str;
	int		i;

	cursor = *binary;
	l = 0;
	while (cursor->next != NULL)
	{
		l++;
		cursor = cursor->next;
	}
	cursor = *binary;
	str = ft_strnew(l);
	i = 0;
	while (i < l)
	{
		str[i] = cursor->content;
		cursor = cursor->next;
		i++;
	}
	return (str);
}

int			*ft_unicode(unsigned int n)
{
ch:w
	   ar	*tab[5];
	char	*binary;
	int		l;
	int		i;
	int		j;

	j = 4;
	while (j > 0)
		tab[j--] = '\0';
	binary = ft_btoa(ft_itob(n));
	l = ft_strlen(binary);
	if (l >= 8)
	{
		tab[0] = 11000000;
		tab[1] = 10000000;
		while (l > 0)
		{
			if (i < 2)
			{
				i = 8;
				j--;
			}
			tab[j][i] = binary[l--];
		}
	}
	if (l >= 12)
		tab[0] = 11100000;
	if (l >= 16)
		tab[0] = 11110000;
	while (l > 0)
	{
		if (l)
		tab[1][i] = binary[l];
	}
}

char	**ft_uniconv(char *binary, int l)
{
	
}
