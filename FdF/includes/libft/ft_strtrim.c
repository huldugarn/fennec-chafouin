/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:47:34 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/05 12:12:25 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s_trim;
	int		b;
	int		e;
	int		a;

	b = 0;
	e = ft_strlen(s) - 1;
	a = 0;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b++;
	if (s[b] == '\0')
		return (ft_strcpy((char *)ft_memalloc(sizeof(char) * 2), ""));
	while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
		e--;
	s_trim = (char *)malloc(sizeof(char) * (e - b + 2));
	if (!s_trim)
		return (NULL);
	while (b <= e)
		s_trim[a++] = s[b++];
	s_trim[a] = '\0';
	return (s_trim);
}
