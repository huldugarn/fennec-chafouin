/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <mareturn_valuein@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:39:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/20 13:39:37 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../Libft/libft.h"	//	adjust
#include <stdio.h>			//	delete
#include <locale.h>

/*int		ft_printf(const char * restrict format, ...)
{
	int             return_value;
	va_list         vl;
	static t_opt	*opt_s;
	int             opt_l;
	int             i;

	if (!(format))
		ft_printf_exit("ft_printf failed due to a format related error");
	setlocale(LC_ALL, "en_US.UTF-8");
	va_start(vl, format);
	return_value = 0;
	opt_s = NULL;
	opt_l = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			opt_l = 1 + o_attr(format, (i + 1), opt_s);
			o_disp(opt_s, 1, 0);//	printf("i = [%i], L = [%i]\n", i, L);
			i = i + opt_l;//	printf("format[i] = %c, nata = [%i]\n", format[i], opt->nata);
			return_value = return_value + c_hub(format, i, opt_s, vl);//	pfps("\n=== CONVERSION - END   ===\n", 1, 0);
		}
		else
			return_value = return_value + pfpc(format[i], 1, 0);
		i++;
	}
	va_end(vl);
	return(return_value);
}*/


int			ft_printf(const char * restrict format, ...)
{
	int		return_value;
	va_list	vl;
	t_list	*splitted_format;
	t_list	*formated_list;

	setlocale(LC_ALL, "en_US.UTF-8");
	va_start(vl, format);
	splitted_format = NULL;
	if (!(format) || !(splitted_format = ft_pf_splist((char *)format)))
		ft_pf_exit("ft_printf failed: format related error");
	formated_list = ft_pf_format(splitted_format, vl);
	return_value = ft_pf_write(ft_pf_concatenate(formated_list));
	free(formated_list);
	free(splitted_format);
	va_end(vl);
	return (return_value);
}

//	~~~~~~~~~~~~~~~~~ WORK HERE ~~~~~~~~~~~~~~~~~	//
t_list		*ft_pf_format(t_list *s_format, va_list vl)
{
	t_list	*f_list;
	t_list	*cursor;
	t_opt	opt_s;

	f_list = NULL;
	cursor = s_format;

/*
**	OPERATION DE MAPPAGE de le liste s_format pour produire une liste f_list.
**	Si l'élément est un marqueur de conversion, utiliser la fonction idoine,
**	sinon mapper sans modifier.
*/
	while (cursor->next != NULL)
	{
		if (((char *)s_format->content)[0] != '%')
			cursor = cursor->next;
		else
		{
			o_attr(cursor->content, &opt_s);
			cursor->content = c_hub(cursor->content, &opt_s, vl);
			cursor = cursor->next;
		}
	}



	return (f_list);
}

int			ft_pf_write(char *string)
{
	char	*start;

	if (!(string))
		ft_pf_exit("ft_pf_write failed: NULL string inputted");
	start = string;
	while (*string)
		ft_putchar((*string)++);
	return (string - start);
}

char		*ft_pf_concatenate(t_list *f_list)
{
	char	*c_string;
	t_list	*cursor;

	c_string = "\0";
	cursor = f_list;
	while (cursor->next != NULL)
	{
		if(!(c_string = ft_strjoin(c_string, (char*)cursor->content)))
			ft_pf_exit("ft_pf_concatenate failed: ft_strjoin related error");
		cursor = cursor->next;
	}
	return (c_string);
}

void	ft_pf_exit(char *message)
{
	ft_putendl(message);
	exit(EXIT_FAILURE);
}