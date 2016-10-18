/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux4_conversions_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:51:13 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/15 15:51:26 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*c_pointer(t_opt *o, va_list vl)
{
	char				*r;
	unsigned long long	tmp;
	int					l;

	tmp = va_arg(vl, unsigned long long);
	r = ft_ullitoa_base(tmp, 16);
	r = ft_strjoin(ft_strndup("0x7fffffffffff", 14 - ft_strlen(r)), r);
	l = ft_strlen(r);
	if (o->mfwd > l)
		r = f_padd(r, o, l);
	return (r);
}

char					*c_di(t_opt *o, va_list vl)
{
	char				*r;
	long long			tmp;
	int					l;

	tmp = type_cast_signed(o, vl);
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

	if (o->ctyp == 'x' || o->ctyp == 'X')
		base = 16;
	else if (o->ctyp == 'o' || o->ctyp == 'O')
		base = 2;
	else
		base = 10;
	if ((tmp = type_cast_unsigned(o, vl)) == 0)
		r = "0";
	else
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

char					*c_oux_l(t_opt *o, va_list vl)
{
	char				*r;
	int					i;

	r = c_oux(o, vl);
	i = 0;
	while (r[i] != '\0')
	{
		r[i] = ft_toupper(r[i]);
		++i;
	}
	return (r);
}
