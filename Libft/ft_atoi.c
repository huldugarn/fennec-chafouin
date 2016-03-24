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

int					ft_atoi(const char *str)
{
	long			nbr;
	long			sign;
	unsigned int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return ((int)(nbr * sign));
}

unsigned int		ft_atob(const char *str)
{
	long			nbr;
	unsigned int	i;

	nbr = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 2 + str[i] - '0';
		i++;
	}
	return ((unsigned int)nbr);
}
