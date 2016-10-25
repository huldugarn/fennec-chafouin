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

int			pf_ascii_display(t_pfs *pfs)
{
	int		n;

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
				ft_putchar(ascii_str[n]);
			++n;
		}
	}
	free(pfs->ascii_str);
	return (n);
}

int			pf_wchar_display(t_pfs *pfs)
{
	int		n;

	n = 0;
	if (pfs->ncex == 0)
	{
		n = ft_uni_strlen(pfs->wchar_str);
		ft_uni_putstr(pfs->wchar_str);
	}
	else
	{
		while (pfs->wchar_str[n] != L'\0')
		{
			if (pfs->wchar_str[n] == L' ')
				ft_uni_putchar(L'\0');
			else
				ft_uni_putchar(wchar_str[n]);
			++n;
		}
	}
	free(pfs->wchar_str);
	return (n);
}
