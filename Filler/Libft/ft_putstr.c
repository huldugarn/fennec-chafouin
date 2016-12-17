/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:11:11 by rle-corr          #+#    #+#             */
/*   Updated: 2015/11/26 15:11:44 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putstr(char const *s)
{
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putwstr_fd(wchar_t const *wstr, int fd)
{
	int	i;

	i = 0;
	while (wstr[i] != L'\0')
	{
		if ((unsigned long)wstr[i] > 127)
			ft_putwchar_fd(wstr[i], fd);
		else
			ft_putchar_fd(wstr[i], fd);
		++i;
	}
}

void	ft_putwstr(wchar_t const *wstr)
{
	ft_putwstr_fd(wstr, 1);
}
