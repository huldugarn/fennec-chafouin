/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1_split_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 16:55:29 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/20 16:55:35 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"	//	adjust
#define CTYP "\%aAcCdDeEfFgGnoOpsSuUxX"

/*char		**ft_split_format(const char * restrict format)
{
	char	**segments_tab;
	int		n;
	int		i;

	n = ft_split_amount(format);
	if (!(segments_tab = (char *)ft_memalloc(sizeof(char *) * (n + 1))))
		return (NULL);
	segments_tab[n] = NULL;
	while (i < n)
	{
		segments_tab[i] = 
	}
	return (segments_tab);
}*/
/*
t_list		*ft_pf_splist(char *s)
{
	t_list	*list;
	int		i;
	int		b;
	int		l;

	list = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		b = i;
		l = 1;
		if (s[i] != '%')
			while (s[++i] != '\0' && s[i] != '%')
				++l;
		else
		{
			while (s[++i] != '\0' && !(ft_strchr(CTYP, s[i])))
				++l;
			++l;
			++i;
		}
		ft_lstpushback(&list, ft_lstnew(ft_strsub(s,b,l), l));
	}
	return (list);
}
*/
void		ft_put_elem(t_list *elem)
{
	ft_putstr((char *)elem->content);
	if (elem->next == NULL)
		ft_putendl("~$~");
}


char		**ft_pf_splist_tab(char *s)
{
	char	**tab;
	int		i;
	int		w;
	int		b;
	int		l;

	if (!(tab = (char**)ft_memalloc((sizeof (char*)) * ft_strlen(s))))
		ft_pf_exit("fuck it all");
	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		b = i;
		l = 1;
		if (s[i] != '%')
			while (s[++i] != '\0' && s[i] != '%')
				++l;
		else
		{
			while (s[++i] != '\0' && !(ft_strchr(CTYP, s[i])))
				++l;
			++l;
			++i;
		}
		tab[w++] = ft_strsub(s,b,l);
	}
	tab[w] = "\0";
	return (tab);
}

char		**ft_pf_formap_tab(char **s_format, va_list vl)
{
	char	**f_tab;
	int		l;
	int		i;

	l = 0;
	while (s_format[l][0] != '\0')
		++l;
	ft_putnbr(l);
	if (!(f_tab = (char**)ft_memalloc((sizeof (char*)) * l)))
		ft_pf_exit("blablabla");
	i = 0;
	ft_putendl("entering formap"); // debug
	while (s_format[i][0] != '\0')
	{
		
	//	ft_putnbr((unsigned int)&(s_format[i])); // debug
	//	ft_putendl(" < current");
		ft_putstr("CONTENT IS:	"); // debug
		ft_putstr(s_format[i]); // debug
		ft_putendl("_");
		
		if (s_format[i][0] == '%')
		{
			ft_putendl("	CASE 1:	editing content"); // debug
			f_tab[i] = ft_strdup(c_hub(s_format[i], vl));
		}
		else
		{
			ft_putendl("	CASE 2:	copy only"); // debug
			f_tab[i] = ft_strdup(s_format[i]);
		}
		++i;
	}
	f_tab[i] = "\0";
	ft_putendl("after formap_tab"); // debug
	return (f_tab);
}

char		*ft_pf_concatenate_tab(char **f_tab)
{
	char	*c_string;
	int		i;

	i = 0;
	c_string = "\0";
	while (f_tab[i][0] != '\0')
	{
	//	ft_putchar('@');
		//ft_putstr(f_tab[i]);
		if (i == 0)
			c_string = ft_strdup(f_tab[i]);
		else
		{
			if(!(c_string = ft_strjoin(c_string, f_tab[i])))
				ft_pf_exit("ft_pf_concatenate failed: ft_strjoin related error");
		}
		++i;
	}
//	ft_putendl(c_string);
	return (c_string);
}
