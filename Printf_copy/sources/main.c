/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <mareturn_valuein@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:39:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/20 13:39:37 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *restrict format, ...)
{
	int		return_value;
	va_list	vl;
	t_list	*splitted_format;
	t_list	*formated_list;

	setlocale(LC_ALL, "en_US.UTF-8");
	va_start(vl, format);
	splitted_format = NULL;
	if (!(format) || !(splitted_format = ft_pf_splist((char *)format, 0)))
		ft_pf_exit("ft_printf failed: format related error");
	formated_list = ft_pf_formap(splitted_format, vl);
	return_value = ft_strlen(ft_pf_concatenate(formated_list));
	free(formated_list);
	free(splitted_format);
	va_end(vl);
	return (return_value);
}

/*
**	----------------------------------------------------------------------------
*/

void		ft_pf_exit(char *message)
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

t_list		*ft_pf_splist(char *format, int i)
{
	t_list	*s_format;
	int		b;
	int		l;

	s_format = NULL;
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
		ft_lstpushback(&s_format, ft_lstnew(ft_strsub(format, b, l), l));
	}
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
	t_opt	*o;
	char	*s;

	f_list = NULL;
	while (s_format)
	{
		if (((char *)s_format->content)[0] == '%')
		{
			o = o_attr(s_format->content, &o);
			s = c_hub(vl, o);
		}
		else
			s = s_format->content;
		ft_lstpushback(&f_list, ft_lstnew(s, ft_strlen(s)));
		s_format = s_format->next;
	}
	return (f_list);
}

/*
**	----------------------------------------------------------------------------
*/

char		*ft_pf_concatenate(t_list *f_list)
{
	char	*c_string;

	c_string = "\0";
	while (f_list != NULL)
	{
		if (!(c_string = ft_strjoin(c_string, (char*)f_list->content)))
			ft_pf_exit("ft_pf_concatenate failed: ft_strjoin related error");
		f_list = f_list->next;
	}
	ft_putstr(c_string);
	return (c_string);
}
