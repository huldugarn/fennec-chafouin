/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:38:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/17 12:39:32 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char		c_type(char *c)
{
	if (ft_strchr("\%npcCsSuUdDioOxXaAeEfFgG", (int)c) == NULL)
		return ('\0');
	else
		return (*c);
}

/* OLD int			c_hub(const char * restrict f, int i, t_opt *o, va_list vl)
{
	int		rv;
	
	rv = 0;
	printf("=== CONVERSION - START ===\n");
	if (f[i] == '%')
		rv = pfpc('%', 1, 0);
	if (f[i] == 'c' || f[i] == 'C')
		rv = (f[i] == 'c') ? (c_char(vl, o, 0)) : (c_char(vl, o, 1));
	if (f[i] == 'i' || f[i + 1] == 'd')
		rv = pfpn(va_arg(vl, int), 1, 0);
	if (f[i] == 's' || f[i] == 'S')
	{
		printf("o->lmod = %i", o->lmod);
		rv = (o->lmod == 3) ? (c_str_s(vl, o, 0)) : (c_str_s(vl, o, 0));
	}
	return (rv);
}*/

char		*c_hub(char *s, t_opt *o, va_list vl)
{
	if (o->ctyp == '%')
		c_percent(s, o, vl);
	else if (o->ctyp == 'n' || o->ctyp == 'p')
		(o->ctyp == 'n') ? (c_n(vl, o, 0)) : (c_p(vl, o, 1));
	else if (s[i] == 'c' || f[i] == 'C')
		(o->ctyp == 'c') ? (c_c(vl, o, 0)) : (c_C(vl, o, 1));
	else if (s[i] == 's' || f[i] == 'S')
		(o->ctyp == 's') ? (c_s(vl, o, 0)) : (c_S(vl, o, 1));
	else
		c_numeric(vl, xxxx);
}

char		*c_percent(char	*s, t_opt **o, va_list vl)
{
	
}