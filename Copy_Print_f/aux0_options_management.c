/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux0_options_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:36:44 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/15 15:36:53 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					o_init(t_opt **opt)
{
	*opt = (t_opt*)malloc(sizeof(t_opt));
	(*opt)->nata = 0;
	(*opt)->altf = 0;
	(*opt)->zpad = 0;
	(*opt)->bpad = 0;
	(*opt)->asig = 0;
	(*opt)->esig = 0;
	(*opt)->tsep = 0;
	(*opt)->mfwd = 0;
	(*opt)->prec = 0;
	(*opt)->lmod = 0;
	(*opt)->ctyp = '\0';
}

t_opt					*o_attr(char *segment, t_opt **opt)
{
	int					i;
	int					l;
	int					t;

	i = 1;
	o_init(opt);
	if ((l = o_nata(&((char *)segment)[i])) > 0)
		(*opt)->nata = ft_atoi(ft_strsub(segment, i, l));
	t = l + o_flag(&((char *)segment)[i + l], (*opt), 0);
	if ((l = o_mfwd(&((char *)segment)[i + t])) > 0)
		(*opt)->mfwd = ft_atoi(ft_strsub(segment, (i + t), l));
	t = t + l;
	if ((l = o_prec(&((char *)segment)[i + t])) > 0)
		(*opt)->prec = ft_atoi(ft_strsub(segment, (i + t + 1), (l - 1)));
	t = t + l;
	if ((l = o_lmod(&((char *)segment)[i + t])) > 0)
		(*opt)->lmod = l;
	if (l != 0 && l > 20)
		t = t + 2;
	else if (l != 0)
		t = t + 1;
	(*opt)->ctyp = *ft_strsub(segment, (i + t), 1);
	return (*(opt));
}

void					o_disp(t_opt *opt)
{
	ft_putnbr(opt->nata);
	ft_putendl("	< NATA");
	ft_putendl(opt->altf ? "[X]	< ALTF" : "[ ]	< ALTF");
	ft_putendl(opt->zpad ? "[X]	< ZPAD" : "[ ]	< ZPAD");
	ft_putendl(opt->bpad ? "[X]	< BPAD" : "[ ]	< BPAD");
	ft_putendl(opt->asig ? "[X]	< ASIG" : "[ ]	< ASIG");
	ft_putendl(opt->esig ? "[X]	< ESIG" : "[ ]	< ESIG");
	ft_putendl(opt->tsep ? "[X]	< TSEP" : "[ ]	< TSEP");
	ft_putnbr(opt->mfwd);
	ft_putendl("	< MFWD");
	ft_putnbr(opt->prec);
	ft_putendl("	< PREC");
	ft_putnbr(opt->lmod);
	ft_putendl("	< LMOD");
	ft_putchar(opt->ctyp);
	ft_putendl("	< CTYP");
}

long long				type_cast_signed(t_opt *o, va_list vl)
{
	long long			tmp;

	tmp = va_arg(vl, long long);
	if (o->lmod == 1 || o->lmod == 21)
		(o->lmod == 21) ?
		(tmp = (char)tmp) :
		(tmp = (short)tmp);
	else if (o->lmod == 2)
		tmp = (intmax_t)tmp;
	else if (o->lmod == 3 || o->lmod == 23 || o->ctyp == 'D')
		(o->lmod == 23) ?
		(tmp = (long long)tmp) :
		(tmp = (long)tmp);
	else if (o->lmod == 4)
		tmp = (long double)tmp;
	else
		tmp = (int)tmp;
	return (tmp);
}

unsigned long long		type_cast_unsigned(t_opt *o, va_list vl)
{
	unsigned long long	tmp;

	tmp = va_arg(vl, unsigned long long);
	if (o->lmod == 1 || o->lmod == 21)
		(o->lmod == 21) ?
		(tmp = (unsigned char)tmp) :
		(tmp = (unsigned short)tmp);
	else if (o->lmod == 2)
		tmp = (uintmax_t)tmp;
	else if (o->lmod == 3 || o->lmod == 23)
		(o->lmod == 23) ?
		(tmp = (unsigned long long)tmp) :
		(tmp = (unsigned long)tmp);
	else
		tmp = (unsigned int)tmp;
	return (tmp);
}
