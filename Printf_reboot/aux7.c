/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:25:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/10/25 16:25:46 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		pf_ascii_display(t_pfs *pfs)
{
	int	n;

	n = 0;
	if (pfs->ncex == 0)
	{
		n = ft_strlen(pfs->ascii_str);
		ft_putstr(pfs->ascii_str);
	}
	else
	{
		while (pfs->ascii_str[n])
		{
			if (pfs->ascii_str[n] == ' ')
				ft_putchar('\0');
			else
				ft_putchar((pfs->ascii_str)[n]);
			++n;
		}
	}
	if (pfs->ascii_str)
		free(pfs->ascii_str);
	return (n);
}

int		pf_wchar_display(t_pfs *pfs)
{
	int	n;

	n = 0;
	if (pfs->ncex == 0)
	{
		n = ft_wstrlen(pfs->wchar_str);
		ft_putwstr(pfs->wchar_str);
	}
	else
	{
		while (pfs->wchar_str[n] != L'\0')
		{
			if (pfs->wchar_str[n] == L' ')
				ft_putwchar(L'\0');
			else
				ft_putwchar((pfs->wchar_str)[n]);
			++n;
		}
	}
	free(pfs->wchar_str);
	return (n);
}

void	pf_sign_management(t_pfs *pfs)
{
	int	i;

	i = 0;
	if (pfs->ctyp == 'd' || pfs->ctyp == 'D' || pfs->ctyp == 'i')
	{
		if (pfs->sign == ' ' && *(pfs->ascii_str) != '-')
			pf_as_pad_insert(&(pfs->ascii_str), " ", 0);
		if (pfs->sign == '+' && *(pfs->ascii_str) != '-' &&
			pfs->ctyp != 'o' && pfs->ctyp != 'O')
			pf_as_pad_insert(&(pfs->ascii_str), "+", 0);
	}
}

void	pf_format_alternate(t_pfs *pfs)
{
	if (*(pfs->ascii_str) != '0' && (pfs->ctyp == 'o' || pfs->ctyp == 'O'))
		pf_as_pad_insert(&(pfs->ascii_str), "0", 0);
	else if (*(pfs->ascii_str) && ft_strcmp(pfs->ascii_str, "0") != 0 &&
		pfs->ctyp == 'x')
		pf_as_pad_insert(&(pfs->ascii_str), "0x", 0);
	else if (*(pfs->ascii_str) && ft_strcmp(pfs->ascii_str, "0") != 0 &&
		pfs->ctyp == 'X')
		pf_as_pad_insert(&(pfs->ascii_str), "0X", 0);
	else if (pfs->ctyp == 'p')
		pf_as_pad_insert(&(pfs->ascii_str), "0x", 0);
}
