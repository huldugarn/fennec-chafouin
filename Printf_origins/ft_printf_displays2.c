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

char *unicheck(wchar_t c)
{
	char *r;

	r = NULL;
	if (c <= 0x7F)
		return (r = unimask1(c));
	if (c <= 0x7FF)
		return (r = unimask2(c));
	if (c <= 0xFFFF)
		return (r = unimask3(c));
	if (c <= 0x10FFFF)
		return (r = unimask4(c));
	return (r);
}

char *unimask1(wchar_t c)
{
	char *r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	r[0] = c;
	r[1] = '\0';
	return (r);
}

char *unimask2(wchar_t c)
{
	char *r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 3)))
		return (NULL);
	r[0] = ((c >> 6) + 0xC0);
	r[1] = ((c & 0x3F) + 0x80);
	r[2] = '\0';
	return (r);
}

char *unimask3(wchar_t c)
{
	char *r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 4)))
		return (NULL);
	r[0] = ((c >> 12) + 0xE0);
	r[1] = (((c >> 6) & 0x3F) + 0x80);
	r[2] = ((c & 0x3F) + 0x80);
	r[3] = '\0';
	return (r);
}

char *unimask4(wchar_t c)
{
	char *r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 4)))
		return (NULL);
	r[0] = ((c >> 18) + 0xE0);
	r[1] = (((c >> 12) & 0x3F) + 0x80);
	r[2] = (((c >> 6) & 0x3F) + 0x80);
	r[3] = ((c & 0x3F) + 0x80);
	r[4] = '\0';
	return (r);
}