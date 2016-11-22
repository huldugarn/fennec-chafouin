/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lengthmod3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:40:51 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/28 12:44:21 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned short		lmod_houx(va_list vl)
{
	return(va_arg(vl, unsigned short));
}

short				lmod_hdi(va_list vl)
{
	return(va_arg(vl, short));
}

short				*lmod_hn(va_list vl)
{
	return(va_arg(vl, short*));
}

unsigned char		lmod_hhoux(va_list vl)
{
	return(va_arg(vl, unsigned char));
}

char				lmod_hhdi(va_list vl)
{
	return(va_arg(vl, char));
}
