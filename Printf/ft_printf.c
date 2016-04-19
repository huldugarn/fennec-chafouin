/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:53:59 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/19 15:22:36 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../Libft/libft.h"

int	ft_printf(const char * restrict format, ...)
{
	int             rv;
	va_list         vl;
	t_opt			*opt;
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
			i = i + L;
			rv = rv + c_hub(format, i, opt, vl);
		}
		else
			rv = rv + pfpc(format[i], 1, 0);
		i++;
	}
	va_end(vl);
	return(rv);
}
