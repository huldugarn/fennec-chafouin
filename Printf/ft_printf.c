/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:53:59 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/16 16:37:12 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../Libft/libft.h"

int	ft_printf(const char * restrict format, ...)
{
	int             rv;
	va_list         vl;
	static  t_opt   *opt = NULL;
	int             L;
	int             i;

	rv = 0;
	va_start(vl, format);
	opt = o_init(opt);
	L = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			L = 1 + o_attr(format, (i + 1), opt);
			i = i + L;
			rv = rv + c_hub(format, i, vl);
		}
		else
			rv = rv + ft_pf_putc(format[i], 1);
		i++;
	}
	va_end(vl);
	return(rv);
}
