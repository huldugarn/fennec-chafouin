/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:55:29 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/04 12:55:34 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			pf_conversion_hub1(va_list *vl, t_pfs *pfs)
{
	if (pfs->ctyp == 's' || pfs->ctyp == 'S')
	{
		if (pfs->lmod[0] == 'l' || pfs->ctyp == 'S')
			pfs->wchar_str = ft_wstrdup(va_arg(*vl, wchar_t*));
		else
			pfs->ascii_str = ft_strdup(va_arg(*vl, char*));
	}
	else if (pfs->ctyp == 'c' || pfs->ctyp == 'C')
	{
		if (pfs->lmod[0] == 'l' || pfs->ctyp == 'C')
			pf_conv_wchar(vl, pfs);
		else
			pf_conv_char(vl, pfs);
	}
	else if (pfs->ctyp == 'd' || pfs->ctyp == 'D' || pfs->ctyp == 'i')
		pf_conv_integer(vl, pfs);
	else
		pf_conversion_hub2(vl, pfs);
	if (pfs->ascii_str == NULL && pfs->wchar_str == NULL)
		pfs->ascii_str = ft_strdup("(null)");
}

void			pf_conversion_hub2(va_list *vl, t_pfs *pfs)
{
	if (pfs->ctyp == 'p')
	{
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, unsigned long long), 16);
		pfs->altf = 1;
	}
	else if (pfs->ctyp == 'o' || pfs->ctyp == 'O')
		pf_conv_octal(vl, pfs);
	else if (pfs->ctyp == 'u' || pfs->ctyp == 'U')
		pf_conv_unsigned(vl, pfs);
	else if (pfs->ctyp == 'x' || pfs->ctyp == 'X')
		pf_conv_hexadecimal(vl, pfs);
	else if (pfs->ctyp == 'f' || pfs->ctyp == 'F')
		pf_conv_double(vl, pfs);
	else
	{
		pfs->ascii_str = (char*)ft_memalloc(sizeof(char) * 2);
		ft_bzero(pfs->ascii_str, 2);
		pfs->ascii_str[0] = pfs->ctyp;
	}
}

void			pf_conv_wchar(va_list *vl, t_pfs *pfs)
{
	pfs->wchar_str = (wchar_t*)ft_memalloc(sizeof(wchar_t) * 2);
	pfs->wchar_str[0] = va_arg(*vl, wchar_t);
	pfs->wchar_str[1] = L'\0';
	if (pfs->wchar_str[0] == L'\0')
	{
		pfs->ncex = 1;
		pfs->wchar_str[0] = L' ';
	}
}

void			pf_conv_char(va_list *vl, t_pfs *pfs)
{
	pfs->ascii_str = (char*)ft_memalloc(sizeof(char) * 2);
	pfs->ascii_str[0] = va_arg(*vl, int);
	pfs->ascii_str[1] = '\0';
	if (pfs->ascii_str[0] == '\0')
	{
		pfs->ncex = 1;
		pfs->ascii_str[0] = ' ';
	}
}

void			pf_conv_integer(va_list *vl, t_pfs *pfs)
{
	short int	i;
	char		c;

	if (ft_strcmp(pfs->lmod, "l") == 0 || pfs->ctyp == 'D')
		pfs->ascii_str = ft_llitoa_base(va_arg(*vl, long), 10);
	else if (ft_strcmp(pfs->lmod, "ll") == 0)
		pfs->ascii_str = ft_llitoa_base(va_arg(*vl, long long), 10);
	else if (ft_strcmp(pfs->lmod, "z") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, unsigned long long), 10);
	else if (ft_strcmp(pfs->lmod, "j") == 0)
		pfs->ascii_str = ft_ullitoa_base(va_arg(*vl, intmax_t), 10);
	else if (ft_strcmp(pfs->lmod, "h") == 0)
	{
		i = va_arg(*vl, int);
		pfs->ascii_str = ft_itoa_base(i, 10);
	}
	else if (ft_strcmp(pfs->lmod, "hh") == 0)
	{
		c = va_arg(*vl, int);
		pfs->ascii_str = ft_itoa_base(c, 10);
	}
	else
		pfs->ascii_str = ft_itoa_base(va_arg(*vl, int), 10);
}
