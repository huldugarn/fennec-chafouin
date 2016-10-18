/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:22:56 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/06 16:22:58 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		pf_ascii_width(t_pfs *pfs)
{
	int		width;
	int		n;

	pf_width_init(pfs, &width, &n, 1);
	if (*(pfs->ascii_str) == '\0' && pfs->ctyp == 'c')
		++width;
	if (n > width)
		while (n > width)
		{
			if (pfs->pads == 'l')
				pf_as_pad_insert(&(pfs->ascii_str), " ", 0);
			else
				pf_as_pad_append(&(pfs->ascii_str), " ");
			--n;
		}
}

void		pf_ascii_width_comp(t_pfs *pfs)
{
	int		width;
	int		n;

	pf_width_init(pfs, &widthm &n, 1);
	if (n == 0)
		n = 1;
	if (n > width)
		while (n > width)
		{
			if (pfs->pads == 'l')
				if (pfs->ctyp == 'p' ||
					(pfs->altf == 1 && (pfs->ctyp == 'x' || pfs->ctyp == 'X')))
					pf_as_pad_insert(&(pfs->ascii_str), "0", 2);
				else if (*(pfs->ascii_str) == '+' || *(pfs->ascii_str) == '-' ||
					pfs->flag == ' ')
					pf_as_pad_insert(&(pfs->ascii_str), "0", 1);
				else
					pf_as_pad_insert(&(pfs->ascii_str), "0", 0);
			else
				pf_as_pad_append(&(pfs->ascii_str), "0");
			--n;
		}
	else
		pfs->ascii_str[width] = '\0';
}

void		pf_wchar_width(t_pfs *pfs)
{
	int		width;
	int		n;

	pf_width_init(pfs, &widthm &n, 0);
	if (*(pfs->wchar_str) == L'\0' && pfs->ctyp == 'c')
		++width;
	if (n > width)
		while (n > width)
		{
			if (pfs->pads == 'l')
				pf_wc_pad_insert(&(pfs->wchar_str), L" ", 0);
			else
				pf_wc_pad_append(&(pfs->wchar_str), L" ");
			--n;
		}
}

void		pf_wchar_width_comp(t_pfs *pfs)
{
	int		width;
	int		n;

	pf_width_init(pfs, &widthm &n, 1);
	if (n == 0)
		n = 1;
	if (n > width)
		while (n > width)
		{
			if (pfs->pads == 'l')
				if (pfs->altf == 1 && (pfs->ctyp == 'x' || pfs->ctyp == 'X'))
					pf_wc_pad_insert(&(pfs->wchar_str), L"0");
				else if (*(pfs->wchar_str) == '+' || *(pfs->wchar_str) == '-' ||
					pfs->flag == ' ')
					pf_wc_pad_insert(&(pfs->wchar_str), L"0");
				else
					pf_wc_pad_insert(&(pfs->wchar_str), L"0");
			else
				pf_wc_pad_append(&(pfs->wchar_str), L"0");
			--n;
		}
	else
		pfs->wchar_str[width] = L'\0';
}

void		pf_width_init(t_pfs *pfs, int *width, int *n, int switch)
{
	*n = pfs->mfwd;
	width = (switch == 1) ?
	((int)ft_strlen(pfs->ascii_str)) : ((int)ft_uni_strlen(pfs->wchar_str));
}