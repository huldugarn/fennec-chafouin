/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lengthmod1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:17:26 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/28 12:26:45 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wint_t			lmod_lc(va_list vl)
{
	return(va_arg(vl, wint_t));
}

wchar_t			*lmod_ls(va_list vl)
{
	return(va_arg(vl, wchar_t*));
}

unsigned long	lmod_loux(va_list vl)
{
	return(va_arg(vl, unsigned long));
}

long			lmod_ldi(va_list vl)
{
	return(va_arg(vl, long));
}

double			lmod_laefg(va_list vl)
{
	return(va_arg(vl, double));
}
