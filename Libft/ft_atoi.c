/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:34:59 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/24 17:49:59 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atox_index_in_base(char c, const char *base)
{
	int				i;

	i = 0;
	while (base[i] && base[i] != c)
		++i;
	return (i);
}

int					ft_atoi_base(const char *str, const char *base)
{
	int				n;
	int				s;
	int				l;
	int				i;

	n = 0;
	s = 1;
	l = ft_strlen(base);
	i = 0;
	while (ft_strchr(" \t\v\r\n\f", str[i]) != NULL)
		++i;
	if (str[i] == '-' || str[i] == '+')
		s = (str[i++] == '-') ? -1 : 1;
	while (ft_atox_index_in_base(str[i], base) < l)
		n = (n * l) + ft_atox_index_in_base(str[i++], base);
	return (n * s);
}

int					ft_atoi(const char *str)
{
	return (ft_atoi_base(str, "0123456789"));
}
