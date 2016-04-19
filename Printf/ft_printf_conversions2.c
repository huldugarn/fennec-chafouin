/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:17:07 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/19 12:06:59 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"

int		c_char(va_list vl, t_opt *opt)
{
	int	rv;

	rv = 0;
	if (opt->mfwd > 1 && opt->zpad == 1)
		while (opt->mfwd-- > 1)
			rv = rv + ft_pf_putc('0', 1);
	rv = rv + ft_pf_putc(va_arg(vl, int), 1);
	if (opt->mfwd > 1 && opt->bpad == 1)
		while (opt->mfwd-- > 1)
			rv = rv + ft_pf_putc(' ', 1);
	return (rv);
}

int		c_CHAR(va_list vl, t_opt *opt)
{
	int	rv;

	rv = 0;
	if (opt->mfwd != 0)
		rv = ft_pf_putc(ft_toupper(va_arg(vl, int)), 1);
	return (rv);
}

int		c_string(va_list vl, t_opt *opt)
{
	int	rv;

	rv = 0;
	if (opt->mfwd != 0)
		rv = ft_pf_puts(va_arg(vl, char*), 1);
	return (rv);
}

int		c_STRING(va_list vl, t_opt *opt)
{
	int	rv;

	rv = 0;
	if (opt->mfwd != 0)
		rv = ft_pf_puts(va_arg(vl, char*), 1);
	return (rv);
}
