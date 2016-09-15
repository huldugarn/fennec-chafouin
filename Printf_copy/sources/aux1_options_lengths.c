/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1_options_lengths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:41:43 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/15 15:41:51 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	These functions return the lengths of their assigned options
**	Option 1 :	NATA	Next argument to access
**	Option 2 :	#0- +'	Flags (ALTF, ZPAD, BPAD, ASIG, ESIG, TSEP)
**	Option 3 :	MFWD	Minimum field width
**	Option 4 :	PREC	Precision
**	Option 5 :	LMOD	Length modifier
*/

int				o_nata(char *c)
{
	int			n;

	if (*c == '$')
		return (1);
	if (ft_isdigit(*c))
	{
		n = o_nata(c + 1);
		return ((n == 0) ? 0 : (n + 1));
	}
	return (0);
}

int				o_flag(char *c, t_opt *opt, int return_value)
{
	if (*c != '#' && *c != '0' && *c != '-' &&
		*c != ' ' && *c != '+' && *c != '\'')
		return (0);
	return_value = o_flag(c + 1, opt, return_value);
	if (*c == '\'')
		opt->tsep = 1;
	else if (*c == '+')
	{
		opt->esig = 1;
		opt->asig = 0;
	}
	else if (*c == ' ' && opt->esig == 0)
		opt->asig = 1;
	else if (*c == '-')
	{
		opt->bpad = 1;
		opt->zpad = 0;
	}
	else if (*c == '0' && opt->bpad == 0)
		opt->zpad = 1;
	else if (*c == '#')
		opt->altf = 1;
	return (return_value + 1);
}

int				o_mfwd(char *c)
{
	int			i;

	i = 1;
	if (ft_isdigit(*c) && *c != '0')
		while (ft_isdigit(*(c + i)))
			i++;
	else
		return (0);
	return (i);
}

int				o_prec(char *c)
{
	int			i;

	i = 1;
	if (*c == '.')
		while (ft_isdigit(*(c + i)))
			i++;
	else
		return (0);
	return (i);
}

int				o_lmod(char *c)
{
	if (*c == 'h')
		return ((*(c + 1) == 'h') ? 21 : 1);
	if (*c == 'j')
		return (2);
	if (*c == 'l')
		return ((*(c + 1) == 'l') ? 23 : 3);
	if (*c == 'L')
		return (4);
	if (*c == 'q')
		return (5);
	if (*c == 't')
		return (6);
	if (*c == 'z')
		return (7);
	return (0);
}
