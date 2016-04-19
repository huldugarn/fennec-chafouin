/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:38:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/19 11:44:59 by rle-corr         ###   ########.fr       */
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

int		c_hub(const char * restrict f, int i, t_opt *o, va_list vl)
{
	int		rv;

	rv = 0;
	if (f[i] == '%')
		rv = ft_pf_putc('%', 1);
	if (f[i] == 'c' || f[i] == 'C')
		rv = (f[i] == 'c') ? (c_char(vl, o)) : (c_CHAR(vl, o));
	if (f[i] == 'i' || f[i + 1] == 'd')
		rv = ft_pf_putn(va_arg(vl, int), 1, 0);
	if (f[i] == 's')
		rv = ft_pf_puts(va_arg(vl, char*), 1);
	return (rv);
}