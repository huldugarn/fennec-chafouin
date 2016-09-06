/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:38:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/17 12:39:32 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char		c_type(char *c)
{
	if (ft_strchr("\%npcCsSuUdDioOxXaAeEfFgG", (int)c) == NULL)
		return ('\0');
	else
		return (*c);
}

char		*c_hub(char *s, va_list vl)
{
	char	*r;
	t_opt	*o;

	if (!s)
		ft_pf_exit("ft_printf failed: conversion related error");
	r = "\0";
	o = o_attr(s, &o);
//	o_disp(o, 1, 0);//	DISPLAY
	if (o->ctyp == '%')
		r = c_percent(o, 1);
	else if (o->ctyp == 'c')
		r = c_c(o, vl);
//		(o.lmod == 3) ? (r = c_C(s, o, vl)) : (r = c_c(s, o, vl));
	else if (o->ctyp == 's')
		r = c_s(o, vl);
//		(o.lmod == 3) ? (r = c_S(s, o, vl)) : (r = c_s(s, o, vl));
	else if (o->ctyp == 'd' || o->ctyp == 'i')
		r = c_d(o, vl);

//	else if (o.ctyp == 'n' || o.ctyp == 'p')
//		(o.ctyp == 'n') ? (r = c_n(s, o, vl)) : (r = c_p(s, o, vl));

//	else if (o.ctyp == 'C')
//		r = c_C(s, o, vl);

//	else if (o.ctyp == 'S')
//		r = c_S(s, o, vl);
//	else
//		r = c_numeric(s, o, vl);
//	free(vl); //supp
//	free(&o);
//	ft_putendl("conversion hub ended"); // debug
	return (r);
}

char		*c_percent(t_opt *o, int l)
{
	char	*r;

	r = "\%\0";
	if (o->mfwd > 1)
		r = f_padd(r, o, l);
	return (r);
}

char		*c_c(t_opt *o, va_list vl)
{
	char	*r;
	char	c;

	r = ft_strnew(1);
	c = va_arg(vl, int);
	r[0] = c;
	if (o->mfwd > 1)
		r = f_padd(r, o, 1);
	return (r);
}

char		*c_s(t_opt *o, va_list vl)
{
	char	*r;
	int		l;

	r = va_arg(vl, char*);
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
	return (r);
}

char		*c_d(t_opt *o, va_list vl)
{
	char	*r;
	size_t	d;
	int		l;

//	if (o->lmod == 1 || o->lmod == 2)
//		(o->lmod == 1) ? (d = va_arg(vl, char)) : (d = va_arg(vl, short));
//	else if (o->lmod == 3 || o->lmod == 4)
//		(o->lmod == 3) ? (d = va_arg(vl, long)) : (d = va_arg(vl, long long));
//	else if (o->mod == 5 || o->lmod == 6)
//		o->lmod == 5 ? d = va_arg(vl, intmax_t) : d = va_arg(vl, ptrdiff_t);
//	else if (o->mod == 8 || o->lmod == 9)
//		o->lmod == 5 ? d = va_arg(vl, quad_t) : d = va_arg(vl, long double);
//	else
		d = va_arg(vl, int);
	r = ft_itoa(d);
	r = f_prec(r, o, ft_strlen(r));
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
	return (r);
}

char	*f_prec(char *s, t_opt *o, int l)
{
	char	*r;
	int		i;

	r = ft_strnew(o->prec);
	i = 0;
	while (i < o->prec)
		r[i++] = '0';
	return (r = ft_strjoin(ft_strndup(r, o->prec - l), s));
}

char	*f_padd(char *s, t_opt *o, int l)
{
	char	*r;
	char	filler;
	int		i;

	i = 0;
	r = ft_strnew(o->mfwd);
	filler = ' ';
	if (o->bpad == 0 && o->zpad == 1)
		filler = '0';
	while (i < o->mfwd)
		r[i++] = filler;
	if (o->bpad)
		return (r = ft_strnjoin(s, r, o->mfwd - l));
	return (r = ft_strjoin(ft_strndup(r, o->mfwd - l), s));
}