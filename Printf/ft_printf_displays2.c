/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_displays2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 09:59:32 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/12 11:58:20 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	[FUNCTION] wwc	:	write wide character
**	[FUNCTION] umm	:	unicode mask manager
**	[FUNCTION] um2	:	unicode mask size 2
**	[FUNCTION] um3	:	unicode mask size 3
**	[FUNCTION] um4	:	unicode mask size 4
**	[VARIABLE] fd	:	file descriptor
**	[VARIABLE] wc	:	wide character
**	[VARIABLE] ca	:	character array
**	[VARIABLE] caa	:	character array adress
**	[VARIABLE] cas	:	character array size
*/

int			wwc(int fd, void *caa, int cas)
{
	char	*caa_pointer;
	int		i;

	caa_pointer = caa;
	i = 0;
	while (i < cas)
	{
		write(fd, caa_pointer + i, 1);
		i++;
	}
	return(1);
}

int			um2(int fd, char ca[4], wint_t wc)
{
	ca[0] = (((wc & 0X07C0) >> 6) + 0XC0);
	ca[1] = ((wc & 0X003F) + 0X80);
	wwc(fd, ca, 2);
	return(1);
}

int			um3(int fd, char ca[4], wint_t wc)
{
	ca[0] = (((wc & 0XF000) >> 12) + 0XE0);
	ca[1] = (((wc & 0XFC0) >> 6) + 0X80);
	ca[2] = ((wc & 0X3F) + 0X80);
	wwc(fd, ca, 3);
	return(1);
}

int			um4(int fd, char ca[4], wint_t wc)
{
	ca[0] = (((wc & 0X1C0000) >> 18) + 0XF0);
	ca[1] = (((wc & 0X3F000) >> 12) + 0X80);
	ca[2] = (((wc & 0XFC0) >> 6) + 0X80);
	ca[3] = ((wc & 0X3F) + 0X80);
	wwc(fd, ca, 4);
	return(1);
}

int			umm(int fd, wint_t wc)
{
	char	ca[4];

	if (wc <= 127)
		return(wwc(fd, &wc, 1));
	else if	(wc <= 2047)
		return(um2(fd, ca, wc));
	else if (wc <= 65535)
		return(um3(fd, ca, wc));
	else if(wc <= 1114111)
		return(um4(fd, ca, wc));
	return(0);
}
