/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:32:37 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/18 17:00:38 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h> // a supp

void				gnl_copyni(const char *buffer, char *dst, int n, int i)
{
	int				d;

	d = 0;
	while (n > 0)
	{
		dst[d] = buffer[i + d];
		d++;
		n--;
	}
	dst[d] = '\0';
}

char				**gnl_split(char *buffer)
{
	char			**tab;
	unsigned long	i;

	if (!(tab = (char**)malloc(sizeof(char *) * 3)))
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!(tab[0] = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (!(tab[1] = (char *)malloc(sizeof(char) * (BUFF_SIZE - i))))
		return (NULL);
	gnl_copyni(buffer, tab[0], (int)sizeof(tab[0]) - 1, 0);
	if (i == sizeof(buffer))
		tab[1] = NULL;
	else
		gnl_copyni(buffer, tab[1], (int)sizeof(tab[1]) - 1, i + 1);
	tab[2] = NULL;
	return (tab);
}

int				get_next_line(int const fd, char **line)
{
	int				r;
	char			b[BUFF_SIZE + 1];
	char			**t;
//	char			*p;
	static char		*s;

	if (BUFF_SIZE == 0 || fd < 0)
		return (-1);
//	printf("A1\n");
	while ((r = read(fd, b, BUFF_SIZE)))
	{
//		printf("B1 : r = %i\n", r);
		b[r] = '\0';
//		printf("B2 : b = %s\n", b);
		t = gnl_split(b); // a protéger 
		printf("B3 : t[0] = %s	t[1] = %s\n", t[0], t[1]);
		if (t[1] == NULL)
		{
//			printf("D0 : line = %s\n", *line);
			printf("D1 : s = %s\n", s);
			if (!s && !line)
			{
				*line = t[0];
			}
			else
			{
		//		if (s)
		//			p = ft_strjoin(s, t[0]);
		//		else
					*line= ft_strjoin(*line, t[0]);
			}
			printf("D2 : p = %s\n", *line);
//			*line = p;
//			printf("D : line = %s\n", *line);
			printf("E1\n");
//			free(s);
		}
		else
		{
			printf("D22\n");
			s = t[1];
			return (r == 0 ? 0 : 1);
		}
	}
	return (-1);
}
