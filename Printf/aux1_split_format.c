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

void		ft_put_elem(t_list *elem)
{
	ft_putendl((char *)elem->content);
}