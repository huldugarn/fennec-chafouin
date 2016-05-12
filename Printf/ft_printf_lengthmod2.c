/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lengthmod2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:33:18 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/28 12:39:39 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long				*lmod_ln(va_list vl)
{
	return(va_arg(vl, long*));
}

unsigned long long	lmod_lloux(va_list vl)
{
	return(va_arg(vl, unsigned long long));
}

long long			lmod_lldi(va_list vl)
{
	return(va_arg(vl, long long));
}

long long			*lmod_lln(va_list vl)
{
	return(va_arg(vl, long long*));
}

long double			lmod_Laefg(va_list vl)
{
	return(va_arg(vl, long double));
}
