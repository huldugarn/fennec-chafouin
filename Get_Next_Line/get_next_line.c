/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:32:37 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/16 15:52:53 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char			*ft_newline(char *buffer)
{
	static char	*n;
	int			b;
	char		*newline;
	int			u;

	b = 0;
	while (buffer[b] != '\n' && buffer[b] != '\0')
		b++;
	(n == NULL) ? (u = 0) : (u = ft_strlen(n));
	if (!(newline = (char*)ft_memalloc(u + b + 1)))
			return (NULL);
	newline[b] = '\0';
	newline = n;
	free(n);
//	ft_putstr("H\n");
//	ft_putstr("buffer :");
//	ft_putstr(buffer);
//	ft_putstr("\n");
	(u == 0) ? (newline = buffer) : (newline = ft_strjoin(newline, buffer));
//	ft_putstr("I\n");
//	ft_putstr(newline);
//	ft_putstr(" <- newline\n");
	if (buffer[b] == '\n')
	{
		if (!(n = (char*)malloc(BUFF_SIZE - b)))
			return (NULL);
		n = &buffer[b + 1];
	}
//	ft_putstr("J\n");
	return (newline);
}

int				get_next_line(int const fd, char **line)
{
	int			r;
	char		b[BUFF_SIZE + 1];
	char		*p;

	if (BUFF_SIZE < 1 || fd < 0)
		return (-1);
	if ((r = read(fd, b, BUFF_SIZE)) == -1)
		return (-1);
	b[r] = '\0';
//	ft_putstr("E\n");
	p = ft_newline(b);
//	ft_putstr("K\n");
//	ft_putnbr(ft_strlen(p));
//	if (!(*line = (char*)ft_memalloc(ft_strlen(p) + 1)))
//		return (0);
//	ft_putstr("L\n");
	line = &p;
//	ft_putstr("M\n");
	ft_putstr(*line);
//	ft_putstr("\n");
//	ft_putstr("N\n");
	return (r == 0 ? 0 : 1);
}
