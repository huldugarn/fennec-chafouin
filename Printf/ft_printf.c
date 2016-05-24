/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:53:59 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/17 14:20:42 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../Libft/libft.h"
#include <stdio.h>

int	ft_printf(const char * restrict format, ...)
{
	int             rv;
	va_list         vl;
	static t_opt	*opt;
	int             L;
	int             i;

	rv = 0;
	va_start(vl, format);
	opt = NULL;
	L = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			L = 1 + o_attr(format, (i + 1), opt);
			o_disp(opt, 1, 0);
			printf("i = [%i], L = [%i]\n", i, L);
			i = i + L;
			printf("format[i] = %c, nata = [%i]\n", format[i], opt.nata);
			rv = rv + c_hub(format, i, opt, vl);
			pfps("\n=== CONVERSION - END   ===\n", 1, 0);
		}
		else
			rv = rv + pfpc(format[i], 1, 0);
		i++;
	}
	va_end(vl);
	return(rv);
}
