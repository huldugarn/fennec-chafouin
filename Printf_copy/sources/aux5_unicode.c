/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux5_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:53:39 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/15 15:53:48 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*unicheck(wchar_t c)
{
	char	*r;

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

char		*unimask1(wchar_t c)
{
	char	*r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	r[0] = c;
	r[1] = '\0';
	return (r);
}

char		*unimask2(wchar_t c)
{
	char	*r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 3)))
		return (NULL);
	r[0] = ((c >> 6) + 0xC0);
	r[1] = ((c & 0x3F) + 0x80);
	r[2] = '\0';
	return (r);
}

char		*unimask3(wchar_t c)
{
	char	*r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 4)))
		return (NULL);
	r[0] = ((c >> 12) + 0xE0);
	r[1] = (((c >> 6) & 0x3F) + 0x80);
	r[2] = ((c & 0x3F) + 0x80);
	r[3] = '\0';
	return (r);
}

char		*unimask4(wchar_t c)
{
	char	*r;

	if (!(r = (char *)ft_memalloc(sizeof(char) * 4)))
		return (NULL);
	r[0] = ((c >> 18) + 0xE0);
	r[1] = (((c >> 12) & 0x3F) + 0x80);
	r[2] = (((c >> 6) & 0x3F) + 0x80);
	r[3] = ((c & 0x3F) + 0x80);
	r[4] = '\0';
	return (r);
}
