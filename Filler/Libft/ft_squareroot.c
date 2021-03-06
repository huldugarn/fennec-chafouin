/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squareroot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:06:16 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/30 13:07:43 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_squareroot(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}
