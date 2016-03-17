/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uniconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:46:10 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/17 11:20:25 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		**ft_itob(unsigned int i)
{
	t_list			*bit;
	t_list			**binary;
	unsigned int	t;

	bit = NULL;
	binary = &bit;
	while (i > 0)
	{
		t = i % 2;
		ft_lstadd(binary, ft_lstnew(&t, 1));
		i = i / 2;
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
		str[i] = *ft_itoa((int)cursor->content);
		cursor = cursor->next;
		i++;
	}
	return (str);
}
