/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3_conversions_alpha.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:50:15 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/15 15:50:27 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

char		*c_c_l(t_opt *o, va_list vl)
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

char		*c_s_l(t_opt *o, va_list vl)
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
