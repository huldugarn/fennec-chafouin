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
	else if (o->ctyp == 'C')
		r = c_C(o, vl);
	else if (o->ctyp == 's')
		r = c_s(o, vl);
	else if (o->ctyp == 'S')
		r = c_S(o, vl);
//		(o.lmod == 3) ? (r = c_S(s, o, vl)) : (r = c_s(s, o, vl));
	else if (o->ctyp == 'd' || o->ctyp == 'D' || o->ctyp == 'i')
		r = c_di(o, vl);
	else if (o->ctyp == 'o' || o->ctyp == 'u' || o->ctyp == 'x')
		r = c_oux(o, vl);
	else if (o->ctyp == 'O' || o->ctyp == 'U' || o->ctyp == 'X')
		r = c_OUX(o, vl);
	else if (o->ctyp == 'p')
		r = c_pointer(o, vl);

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

char						*c_pointer(t_opt *o, va_list vl)
{
	char					*r;
	unsigned long long int	tmp;
	int						l;

	tmp = va_arg(vl, unsigned long long int);
	r = ft_ullitoa_base(tmp, 16);
	r = ft_strjoin(ft_strndup("0x7fffffffffff", 14 - ft_strlen(r)), r);
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
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

	r = ft_strnew(1);
	r[0] = (char)va_arg(vl, int);
	if (o->mfwd > 1)
		r = f_padd(r, o, 1);
	return (r);
}

char		*c_C(t_opt *o, va_list vl)
{
	char	*r;

	r = ft_strnew(1);
	r = unicheck(va_arg(vl, wchar_t));
	if (o->mfwd > 1)
		r = f_padd(r, o, 1);
	return (r);
}

char		*c_s(t_opt *o, va_list vl)
{
	char	*r;
	int		l;

	if (!(r = va_arg(vl, char*)))
		return ("(null)");
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
	return (r);
}

char		*c_S(t_opt *o, va_list vl)
{
	char	*r;
	wchar_t	*s;
	int		l;

	r = "\0";
	if (!(s = va_arg(vl, wchar_t*)))
		return ("(null)");
	while (*s)
		r = ft_strjoin(r, unicheck(*(s++)));
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
	return (r);
}

char				*c_di(t_opt *o, va_list vl)
{
	char			*r;
	long long int	tmp;
	int				l;

	tmp = va_arg(vl, long long int);
	if (o->lmod == 1 || o->lmod == 21)
		(o->lmod == 21) ? (tmp = (char)tmp) : (tmp = (short)tmp);
	else if (o->lmod == 2)
		tmp = (intmax_t)tmp;
	else if (o->lmod == 3 || o->lmod == 23 || o->ctyp == 'D')
		(o->lmod == 23) ? (tmp = (long long)tmp) : (tmp = (long)tmp);
	else if (o->lmod == 4)
		tmp = (long double)tmp;
	else
		tmp = (int)tmp;
	r = ft_llitoa(tmp);
	if (tmp >= 0 && (o->asig || o->esig))
		r = f_sign(r, o);
	if (o->prec)	
		r = f_prec(r, o, ft_strlen(r));
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
	if (o->prec == 0 && tmp == 0)
		return ("");
	return (r);
}

char					*c_oux(t_opt *o, va_list vl)
{
	char				*r;
	unsigned long long	tmp;
	int					l;
	int					base;

	if (o->ctyp == 'u' || o->ctyp == 'U')
		base = 10;
	else
		(o->ctyp == 'o' || o->ctyp == 'O') ? (base = 2) : (base = 16);
	tmp = va_arg(vl, unsigned long long);
	if (o->lmod == 1 || o->lmod == 21)
		(o->lmod == 21) ? (tmp = (unsigned char)tmp) :
		 (tmp = (unsigned short)tmp);
	else if (o->lmod == 2)
		tmp = (uintmax_t)tmp;
	else if (o->lmod == 3 || o->lmod == 23)
		(o->lmod == 23) ? (tmp = (unsigned long long)tmp) :
		 (tmp = (unsigned long)tmp);
	else
		tmp = (unsigned int)tmp;
	r = ft_ullitoa_base(tmp, base);
	if (o->prec)	
		r = f_prec(r, o, ft_strlen(r));
	if (o->altf)
		r = f_altf(r, o);
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
	return (r);
}

char						*c_OUX(t_opt *o, va_list vl)
{
	char					*r;
	int						i;

	r = c_oux(o, vl);
	i = 0;
	while (r[i] != '\0')
	{
		r[i] = ft_toupper(r[i]);
		++i;
	}
	return (r);
}

char		*f_altf(char *s, t_opt *o)
{
	char	*r;

	if (o->ctyp == 'x' || o->ctyp == 'X' || o->ctyp == 'p')
		ft_islower(o->ctyp) ? (r = ft_strjoin("0x", s)) :
		 (r = ft_strjoin("0X", s));
	else
		r = s;
	return (r);
}

char	*f_prec(char *s, t_opt *o, int l)
{
	char	*r;
	int		i;

	if ((o->ctyp == 'o' || o->ctyp == 'O') && o->altf)
		++l;
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

char	*f_sign(char *s, t_opt *o)
{
	char	*r;

	if (o->esig)
		return (r = ft_strjoin("+\0", s));
	return (r = ft_strjoin(" \0", s));
}