/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:36:46 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/29 14:36:55 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	pf_color_mask(char *s)
{
	if (ft_strcmp(s, "BLK") == 0)
		write(1, "\033[30m", 5);
	else if (ft_strcmp(s, "RED") == 0)
		write(1, "\033[31m", 5);
	else if (ft_strcmp(s, "GRN") == 0)
		write(1, "\033[32m", 5);
	else if (ft_strcmp(s, "YLW") == 0)
		write(1, "\033[33m", 5);
	else if (ft_strcmp(s, "BLU") == 0)
		write(1, "\033[34m", 5);
	else if (ft_strcmp(s, "MGT") == 0)
		write(1, "\033[35m", 5);
	else if (ft_strcmp(s, "CYA") == 0)
		write(1, "\033[36m", 5);
	else if (ft_strcmp(s, "WHT") == 0)
		write(1, "\033[37m", 5);
	else
		return (0);
	return (1);
}

static int	pf_color_test(const char *restrict format)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strdup(format);
	while (s[i])
	{
		if (s[i] == '}')
		{
			s[i] = '\0';
			--i;
		}
		++i;
	}
	i = pf_color_mask(s);
	free(s);
	return (i);
}

static void	pf_color(char **format, int *n)
{
	if (pf_color_test(*format++) == 1)
	{
		while (**format != '}')
			*format = *format + 1;
	}
	else
	{
		write(1, *format, 1);
		*n = *n + 1;
	}
}

static void	pf_loop(const char *restrict format, va_list *vl, int *n)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'n')
				*(va_arg(*vl, int*)) = *n;
			else
			{
				*n = *n + pf_read_and_display(format, vl);
				while (ft_strchr(PF_FC, *format) != NULL && *format)
					++format;
			}
		}
		else if (*format == '{')
			pf_color((char **)(&format), n);
		else
		{
			write(1, format, 1);
			*n = *n + 1;
		}
		if (*format)
			++format;
	}
}

int			ft_printf(const char *restrict format, ...)
{
	int		n;
	va_list	vl;

	n = 0;
	va_start(vl, format);
	pf_loop(format, &vl, &n);
	va_end(vl);
	return (n);
}
