/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:38:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/16 16:38:52 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	c_type(char *c)
{
	if (ft_strchr("\%npcCsSuUdDioOxXaAeEfFgG", (int)c) == NULL)
		return ('\0');
	else
		return (*c);
}

int		c_hub(const char * restrict format, int i, va_list vl)
{
	int		return_value;

	return_value = 0;
	if (format[i] == '%')
		return_value = ft_pf_putc('%', 1);
	if (format[i] == 'c')
		return_value = ft_pf_putc(va_arg(vl, int), 1);
	if (format[i] == 'i' || format[i + 1] == 'd')
		return_value = ft_pf_putn(va_arg(vl, int), 1, 0);
	if (format[i] == 's')
		return_value = ft_pf_puts(va_arg(vl, char*), 1);
	return (return_value);
}
