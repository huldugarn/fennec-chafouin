/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:02:57 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/26 13:26:47 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_absolu(int n)
{
	return ((n < 0) ? -n : n);
}

long		ft_power(int n, int e)
{
	long	r;

	r = 1;
	if (e == 0)
		return (1);
	if (e < 0)
		return (1 / ft_power(n, ft_absolu(e)));
	while (e > 0)
	{
		r = r * (long)n;
		--e;
	}
	return (r);
}

int		ft_squareroot(int a)
{
	int x;

	x = 1;
	if (a == 4)
		return (2);
	if (a == 9)
		return (3);
	if (a == 16)
		return (4);
	if (a == 25)
		return (5);
	if (a > 25)
		while (x < a / 5)
		{
			if (x * x == a)
				return (x);
			else
				x++;
		}
	return (0);
}
