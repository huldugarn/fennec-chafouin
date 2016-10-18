/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:18:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/29 15:18:27 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

int			pf_read_and_display(const char *restrict format, va_list *vl)
{
	t_pfs	pfs;
	int		i;

	pf_structure_init(&pfs);
	pf_options_assign(&pfs, format);
	if (pfs.ctyp == '\0')
		return (0);
	pf_check_pads(&pfs, format);
	pf_check_lmod(&pfs, format);
	pf_check_prec_mfwd(&pfs, format, vl);
	pf_gestion_params(&pfs, vl);
	if (pfs.ascii_str != NULL)
		return (pf_ascii_manage(&pfs));
	else if (pfs.wchar_str != NULL)
		return (pf_wchar_manage(&pfs));
	else
		return (0);
}

static void	pf_structure_init(t_pfs *pfs)
{
	pfs->flag = '0';
	pfs->prec = 0;
	pfs->prec_flag = 0;
	pfs->mfwd = 0;
	pfs->mfwd_flag = 0;
	pfs->altf = 0;
	pfs->negation = 0;
	pfs->ncex = 0;
	ft_bzero(pfs->lmod, 3);
	pfs->ascii_str = NULL;
	pfs->wchar_str = NULL;
}

static void	pf_options_assign(const char *restric format, t_pfs *pfs)
{
	while (ft_strchr(" .*#+-0123456789jhlLz") != NULL && *format)
	{
		if (*format == '#')
			pfs->altf = 1;
		if (*format == '-')
		{
			pfs->negation = 1;
			pfs->pads = 'r';
		}
		if (*format == '+')
			pfs->pads = '+';
		if (*format == ' ' && pfs->flag != '+')
			pfs->pads = ' ';
		*format++;
	}
	pfs->ctyp = (char)*format;
}

static int	pf_ascii_manage(t_pfs *pfs)
{
	pf_ascii_prec(pfs);
	pf_options_management(pfs);
	if (pfs->altf == 1)
		pf_format_alternate(pfs);
	if (pfs->mfwd_flag == 1 && pfs->negation == 0 && pfs->prec <= 0)
		pf_ascii_width_comp(pfs);
	else
		pf_ascii_width(pfs);
	return (pf_ascii_display(pfs))
}

static int	pf_wchar_manage(t_pfs *pfs)
{
	pf_wchar_prec(pfs);
	if (pfs->mfwd_flag == 1 && pfs->negation == 0 && pfs->prec <= 0)
		pf_wchar_width_comp(pfs);
	else
		pf_wchar_width(pfs);
	return (pf_wchar_display(pfs))
}
