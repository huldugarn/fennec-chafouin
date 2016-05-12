/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:17:07 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/12 14:37:24 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int			c_char(va_list vl, t_opt *o, int tc)
{
	int		r;

	r = 0;
	printf("case : [%i]\n", tc);
	pfpn(o->mfwd, 1, 0);
	printf("bpad : [%i]\n", o->bpad);
	if (o->mfwd > 1 && o->bpad == 0)
	{
		pfps("test\n",1, 0);
		while (o->mfwd-- > 1)
			(o->zpad == 1) ? (r += pfpc('0', 1, tc)) : (r += pfpc(' ', 1, tc));
	}
	printf("mfwd OK\n");
	if (o->lmod == 3 || tc == 1)
		r = r + pfpc(va_arg(vl, wint_t), 1, tc);
	else
	{
		printf("case : [%i]\n", tc);
		r = r + pfpc(va_arg(vl, int), 1, tc);
	}
	if (o->mfwd > 1 && o->bpad == 1)
		while (o->mfwd-- > 1)
			r = r + pfpc(' ', 1, tc);
	return (r);
}

int			c_str_s(va_list vl, t_opt *o, int tc)
{
	int		r;
	char	*str;
	int		l;

	r = 0;
	if (o->prec != 0)
		str = ft_strndup(va_arg(vl, char*), o->prec);
	else
		str = ft_strdup(va_arg(vl, char*));
//	(P != 0) ? (st = SN(VA(vl, char*), P)) : (st = SD(va(vl, char*)));
	l = ft_strlen(str);
	if (o->mfwd > l && o->bpad == 0)
		while (o->mfwd-- > l)
			(o->zpad == 1) ? (r += pfpc('0', 1, tc)) : (r += pfpc(' ', 1, tc));
	r = r + pfps(str, 1, tc);
	if (o->mfwd > l && o->bpad == 1)
		while (o->mfwd-- > l)
			r = r + pfpc(' ', 1, tc);
	return (r);
}

/*
//	requiert pfps, ft_strdup, ft_strndup & ft_strlen compatible avec wchar_t*
int			c_str_l(va_list vl, t_opt *o, int tc)
{
	int		r;
	wchar_t	*str;
	int		l;

	r = 0;
	if (o->prec != 0)
		str = ft_strndup(va_arg(vl, wchar_t*), o->prec);
	else
		str = ft_strdup(va_arg(vl, wchar_t*));
//	(P != 0) ? (str = SN(VA(vl, wchar_t*), P)) : (str = SD(va(vl, wchar_t*)));
	l = ft_strlen(str);
	if (o->mfwd > l && o->bpad == 0)
		while (o->mfwd-- > l)
			(o->zpad == 1) ? (r += pfpc('0', 1, tc)) : (r += pfpc(' ', 1, tc));
	r = r + pfps(str, 1, tc);
	if (o->mfwd > l && o->bpad == 1)
		while (o->mfwd-- > l)
			r = r + pfpc(' ', 1, tc);
	return (r);
}*/
