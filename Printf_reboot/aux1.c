/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:11:27 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/29 16:11:32 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

void	pf_check_pads(t_pfs *pfs, const char *restrict format)
{
	pfs->pads = 'l';
	while (*format != pfs->ctyp)
	{
		if (*format == '-')
			pfs->pads = 'r';
		format++;
	}
}

void	pf_check_lmod(t_pfs *pfs, const char *restrict format)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (*format != pfs->ctyp && *format)
	{
		if (ft_strchr("jhlLz", (char)*format))
		{
			pfs->lmod[width] = (char)*format;
			width++;
		}
		i++;
	}
}

void	pf_check_prec_mfwd(t_pfs *pfs, const char *restrict format,
		va_list *vl)
{
	int	i;

	i = 0;
	while (format[i] != pfs->ctyp)
	{
		if (format[i] == '.')
			pf_fw_prec(pfs, format, vl, &i);
		else if (ft_isdigit(format[i]) || format[i] == '*')
			pf_fw_mfwd(pfs, format, vl, &i);
		else
			i++;
	}
	if (pfs->mfwd < 0)
	{
		pfs->mfwd = pfs->mfwd * (-1);
		pfs->pads = 'r';
		pfs->negation = 1;
	}
}

void	pf_check_prec(t_pfs *pfs, const char *restrict format,
		va_list *vl, int *i)
{
	*i++;
	if (ft_isdigit(format[*i]))
		pfs->prec = ft_atoi(format + *i);
	else if (format[*i] == '*')
		pfs->prec = va_arg(*vl, long long int);
	else
		pfs->prec = 0;
	while (ft_isdigit(format[*i]) || format[*i] == '*')
		*i++;
}

void	pf_check_mfwd(t_pfs *pfs, const char *restrict format,
		va_list *vl, int *i)
{
	if (format[*i] == '0')
	{
		pfs->mfwd_flag = 1;
		if (format[*i + 1] == '*')
			pfs->mfwd = va_arg(*vl, int);
		else
			pfs->mfwd = ft_atoi(format + *i + 1);
	}
	else if (format[*i] == '*')
		pfs->mfwd = va_arg(*vl, int);
	else
		pfs->mfwd = ft_atoi(format + *i);
	if (ft_isdigit(format[*i]))
		while (ft_isdigit(format[*i]))
			*i++;
	else
		*i++;
}