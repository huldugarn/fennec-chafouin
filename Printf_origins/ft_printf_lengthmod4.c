/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lengthmod4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:49:00 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/28 12:52:33 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

signed char			*lmod_hhn(va_list vl)
{
	return(va_arg(vl, signed char*));
}

uintmax_t			lmod_joux(va_list vl)
{
	return(va_arg(vl, uintmax_t));
}

intmax_t			lmod_jdi(va_list vl)
{
	return(va_arg(vl, intmax_t));
}

intmax_t			*lmod_jn(va_list vl)
{
	return(va_arg(vl, intmax_t*));
}

size_t				lmod_zoux(va_list vl)
{
	return(va_arg(vl, size_t));
}
