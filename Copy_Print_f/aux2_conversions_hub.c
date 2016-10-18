/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2_conversions_hub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:49:09 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/15 15:49:16 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*c_hub(va_list vl, t_opt *o)
{
	char	*r;

	r = "\0";
	if (o->ctyp == '%')
		r = c_percent(o, 1);
	else if (o->ctyp == 'c')
		r = c_c(o, vl);
	else if (o->ctyp == 'C')
		r = c_c_l(o, vl);
	else if (o->ctyp == 's')
		r = c_s(o, vl);
	else if (o->ctyp == 'S')
		r = c_s_l(o, vl);
	else if (o->ctyp == 'd' || o->ctyp == 'D' || o->ctyp == 'i')
		r = c_di(o, vl);
	else if (o->ctyp == 'o' || o->ctyp == 'u' || o->ctyp == 'x')
		r = c_oux(o, vl);
	else if (o->ctyp == 'O' || o->ctyp == 'U' || o->ctyp == 'X')
		r = c_oux_l(o, vl);
	else if (o->ctyp == 'p')
		r = c_pointer(o, vl);
	return (r);
}

char		*f_altf(char *s, t_opt *o)
{
	char	*r;

	if (o->ctyp == 'x' || o->ctyp == 'X' || o->ctyp == 'p')
		ft_islower(o->ctyp) ?
		(r = ft_strjoin("0x", s)) :
		(r = ft_strjoin("0X", s));
	else
		r = s;
	return (r);
}

char		*f_prec(char *s, t_opt *o, int l)
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

char		*f_padd(char *s, t_opt *o, int l)
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

char		*f_sign(char *s, t_opt *o)
{
	char	*r;

	if (o->esig)
		return (r = ft_strjoin("+\0", s));
	return (r = ft_strjoin(" \0", s));
}
