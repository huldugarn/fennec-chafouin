/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:35:46 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/31 16:53:44 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void	ft_error(int code)
{
	if (code == 0)
		write(1, "error\n", 6);
	if (code == 1)
		write(1, "open error\n", 11);
	if (code == 2)
		write(1, "shut error\n", 11);
	if (code == 3)
		write(1, "read error\n", 11);
	if (code == 4)
		write(1, "argv error\n", 11);
	if (code == 5)
		write(1, "grid error\n", 11);
	if (code == 6)
		write(1, "form error\n", 11);
	if (code == 7)
		write(1, "malloc error\n", 13);
	if (code == 8)
		write(1, "nbr t error\n", 12);
	exit(0);
}
