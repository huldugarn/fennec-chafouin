/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:26:20 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/25 16:26:35 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	pf_ascii_prec_init(t_pfs *pfs, int *width, int *n)
{
	*n = pfs->prec;
	*width = ft_strlen(pfs->ascii_str);
	if (*(pfs->ascii_str) == '-' || *(pfs->ascii_str) == '+')
		*width = *width - 1;
}

void	pf_ascii_prec(t_pfs *pfs)
{
	int	width;
	int	n;

	pf_ascii_prec_init(pfs, &width, &n);
	if (n >= 0 && pfs->ctyp != '%' && pfs->ctyp != 'c'
		&& pfs->ctyp != 'f' && pfs->ctyp != 'F')
	{
		if (n == 0 && *(pfs->ascii_str) == '0')
			pfs->ascii_str[0] = '\0';
		else if (pfs->ctyp == 's')
			pfs->ascii_str[n] = '\0';
		else
		{
			while (n > width)
			{
				if (pfs->ctyp == 'x' || pfs->ctyp == 'X')
					pf_as_pad_insert(&(pfs->ascii_str), "0", 0);
				else if (*(pfs->ascii_str) == '+' || *(pfs->ascii_str) == '-')
					pf_as_pad_insert(&(pfs->ascii_str), "0", 1);
				else
					pf_as_pad_insert(&(pfs->ascii_str), "0", 0);
				--n;
			}
		}
	}
}

void	pf_wchar_prec_init(t_pfs *pfs, int *width, int *n, int *i)
{
	*n = pfs->prec;
	*width = 0;
	*i = -1;
}

void	pf_wchar_prec(t_pfs *pfs)
{
	int	width;
	int	n;
	int	i;

	pf_wchar_prec_init(pfs, &width, &n, &i);
	if (n >= 0 && pfs->ctyp != '%' && pfs->ctyp != 'c')
	{
		if (n == 0 && *(pfs->wchar_str) == L'0')
			pfs->wchar_str[0] = L'\0';
		else if (pfs->ctyp == 'S')
		{
			while (n >= width)
			{
				++i;
				width = width + ft_wchar_width(pfs->wchar_str[i]);
			}
			pfs->wchar_str[i] = L'\0';
		}
	}
}
