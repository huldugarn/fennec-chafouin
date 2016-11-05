/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:12:18 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/06 15:12:22 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			pf_conv_octal(va_list *vl, t_pfs *pfs)
{
	if (ft_strcmp(pfs->lmod, "l") == 0 || pfs->ctyp == 'O')
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, long unsigned), 8);
	else if (ft_strcmp(pfs->lmod, "ll") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, long long unsigned), 8);
	else if (ft_strcmp(pfs->lmod, "z") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, size_t), 8);
	else if (ft_strcmp(pfs->lmod, "j") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, uintmax_t), 8);
	else if (ft_strcmp(pfs->lmod, "h") == 0)
		pfs->ascii_str = ft_ullitoa_base(
			(unsigned short)(va_arg(*vl, unsigned int)), 8);
	else if (ft_strcmp(pfs->lmod, "hh") == 0)
		pfs->ascii_str = ft_ullitoa_base(
			(unsigned char)(va_arg(*vl, unsigned int)), 8);
	else
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, unsigned int), 8);
}

void			pf_conv_unsigned(va_list *vl, t_pfs *pfs)
{
	if (ft_strcmp(pfs->lmod, "l") == 0 || pfs->ctyp == 'U')
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, long unsigned), 10);
	else if (ft_strcmp(pfs->lmod, "ll") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, long long unsigned), 10);
	else if (ft_strcmp(pfs->lmod, "z") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, size_t), 10);
	else if (ft_strcmp(pfs->lmod, "j") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, uintmax_t), 10);
	else if (ft_strcmp(pfs->lmod, "hh") == 0)
		pfs->ascii_str = ft_ullitoa_base(
			(unsigned char)(va_arg(*vl, unsigned int)), 10);
	else
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, unsigned int), 10);
}

void			pf_conv_hexadecimal(va_list *vl, t_pfs *pfs)
{
	int			i;

	if (ft_strcmp(pfs->lmod, "l") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, long unsigned), 16);
	else if (ft_strcmp(pfs->lmod, "ll") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, long long unsigned), 16);
	else if (ft_strcmp(pfs->lmod, "z") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, size_t), 16);
	else if (ft_strcmp(pfs->lmod, "j") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, uintmax_t), 16);
	else if (ft_strcmp(pfs->lmod, "hh") == 0)
		pfs->ascii_str = ft_ullitoa_base(
			(unsigned char)(va_arg(*vl, unsigned int)), 16);
	else
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, unsigned int), 16);
	i = 0;
	if (pfs->ctyp == 'X')
		while (pfs->ascii_str[i])
		{
			pfs->ascii_str[i] = ft_toupper(pfs->ascii_str[i]);
			++i;
		}
}

void			pf_conv_double(va_list *vl, t_pfs *pfs)
{
	double		value;
	long long	integer;
	double		decimal;
	char		*str;

	value = va_arg(*vl, double);
	integer = (long long)value;
	decimal = value - integer;
	str = ft_itoa(integer);
	pfs->ascii_str = ft_strjoin(str, ".");
	free(str);
	if ((integer = pfs->prec) == -1)
		integer = 6;
	while (integer-- > 0)
		decimal = decimal * (double)10;
	pf_conv_double_round_up(&decimal);
	str = ft_itoa((long long)decimal);
	ft_strjoin(pfs->ascii_str, str);
	free(str);
	if (pfs->ascii_str == NULL)
		pfs->ascii_str = ft_strdup("(null)");
}

void			pf_conv_double_round_up(double *decimal)
{
	double		d;
	int			i;

	if (*decimal < 0)
		*decimal = *decimal * (-1);
	d = *decimal;
	i = (int)d;
	d = d - i;
	d = (int)(d * 10);
	*decimal = (int)*decimal;
	if (d >= 6)
		*decimal = *decimal + 1;
}
