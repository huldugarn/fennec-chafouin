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
#define CTYP "\%aAcCdDeEfFgGnoOpsSuUxX" // check
/*

	convertir et rendre un char *
récupérer un char * et gerer le padding
*/
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
	formated_list = ft_pf_formap(splitted_format, vl);
	return_value = ft_strlen(ft_pf_concatenate(formated_list));
//	return_value = ft_pf_write(ft_pf_concatenate(formated_list));
	free(formated_list);
	free(splitted_format);
	va_end(vl);
	return (return_value);
}

int			ft_printf_tab(const char * restrict format, ...)
{
	char	*return_string;
	va_list	vl;
	char	**splitted_format;
	char	**formated_tab;

	splitted_format = NULL;
	setlocale(LC_ALL, "en_US.UTF-8");
	va_start(vl, format);
	if (!(format) || !(splitted_format = ft_pf_splist_tab((char *)format)))
		ft_pf_exit("ft_printf failed: format related error");
	formated_tab = ft_pf_formap_tab(splitted_format, vl);
	return_string = ft_pf_concatenate_tab(formated_tab);
	ft_putendl(return_string);
	free(formated_tab);
	free(splitted_format);
	va_end(vl);
	return (ft_strlen(return_string));
}


/*
**	----------------------------------------------------------------------------
*/
void	ft_pf_exit(char *message)
{
	ft_putendl(message);
	exit(EXIT_FAILURE);
}

/*
**	----------------------------------------------------------------------------
**	{ft_pf_splist}	SPLIT AND LIST
**	[format]		chaîne originelle "format" ;
**	Parcours la chaîne [s],
**		Si la position actuelle n'est pas un marqueur de conversion, alors :
**			Parcourir la chaine jusqu'à la fin ou au prochain marqueur,
**		Sinon :
**			Pacourir la chaîne jusqu'à un marqueur de type de conversion,
**		Ajoute une copie de la chaîne de longueur [l] depuis la position [b]
**		à la fin de [s_format],
**	Retourne la liste de segments [s_format].
*/
t_list		*ft_pf_splist(char *format)
{
	t_list	*s_format;
	int		i;
	int		b;
	int		l;

	s_format = NULL;
	i = 0;
	while (format[i] != '\0')
	{
		b = i;
		l = 1;
		if (format[i] != '%')
			while (format[++i] != '\0' && format[i] != '%')
				++l;
		else
		{
			while (format[++i] != '\0' && !(ft_strchr(CTYP, format[i])))
				++l;
			++l;
			++i;
		}
		ft_lstpushback(&s_format, ft_lstnew(ft_strsub(format,b,l), l));
	}
//	ft_lstiter(s_format, ft_put_elem); //debug
	return (s_format);
}

/*
**	----------------------------------------------------------------------------
**	{ft_pf_formap}	FORMAT AND MAP
**	[s_format]		liste de segments de la chaîne originelle "format" ;
**	[vl]			liste variable d'arguments.
**	Parcours les éléments de [s_format],
**		Si le contenu d'un élément est un marqueur de conversion, alors :
**			Appelle {c_hub} pour interpréter le contenu de l'élément,
**			Redéfini la taille de l'élément suite à l'interprétation.
**		Ajoute une copie de l'élément à la fin de [f_list],
**		Poursuit.
**	Retourne la liste de chaînes formattées [f_list].
*/
t_list		*ft_pf_formap(t_list *s_format, va_list vl)
{
	t_list	*f_list;
	char	*s;

	f_list = NULL;
	while (s_format)
	{
		if (((char *)s_format->content)[0] == '%')
			s = c_hub(s_format->content, vl);
		else
			s = s_format->content;
		ft_lstpushback(&f_list, ft_lstnew(s,ft_strlen(s)));
		s_format = s_format->next;
	}
//	ft_lstiter(f_list, ft_put_elem); //debug
	return (f_list);
}

/*
**	----------------------------------------------------------------------------
*/
int			ft_pf_write(char *string)
{
	int		l;

	if (!(string))
		ft_pf_exit("ft_pf_write failed: NULL string inputted");
	l = ft_strlen(string);
	write(1, &string, l);
	return (l);
}

char		*ft_pf_concatenate(t_list *f_list)
{
	char	*c_string;

	c_string = "\0";
	while (f_list != NULL)
	{
		if(!(c_string = ft_strjoin(c_string, (char*)f_list->content)))
			ft_pf_exit("ft_pf_concatenate failed: ft_strjoin related error");
		f_list = f_list->next;
	}
	ft_putstr(c_string);
	return (c_string);
}