/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:17:07 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/19 15:06:12 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"

int			c_char(va_list vl, t_opt *o, int tc)
{
	int		r;

	r = 0;
	if (o->mfwd > 1 && o->bpad == 0)
		while (o->mfwd-- > 1)
			(o->zpad == 1) ? (r += pfpc('0', 1, tc)) : (r += pfpc(' ', 1, tc));
	r = r + pfpc(va_arg(vl, int), 1, tc);
	if (o->mfwd > 1 && o->bpad == 1)
		while (o->mfwd-- > 1)
			r = r + pfpc(' ', 1, tc);
	return (r);
}

int			c_string(va_list vl, t_opt *o, int tc)
{
	int		r;
	char	*str;
	int		l;

	r = 0;
	str = ft_strdup(va_arg(vl, char*));
	l = ft_strlen(str);
	if (o->mfwd > l && o->bpad == 0)
		while (o->mfwd-- > l)
			(o->zpad == 1) ? (r += pfpc('0', 1, tc)) : (r += pfpc(' ', 1, tc));
	r = r + pfps(str, 1, tc);
	if (o->mfwd > l && o->bpad == 1)
		while (o->mfwd-- > l)
			r = r + pfpc(' ', 1, tc);
	return (r);
}
