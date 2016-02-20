/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 10:42:48 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/20 16:48:30 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

t_doc		t_doc_init(int fd, char *str)
{
	t_doc	new_doc;

	new_doc.fd = fd;
	new_doc.lines = ft_strsplit(str, '\n');
	new_doc.i = 0;
	new_doc.next = NULL;
	return (new_doc);
}

int			get_next_line(int const fd, char **line)
{
	char			b[BUFF_SIZE + 1];
	char			*str;
	int				r;
	char			*tmp;
	static t_doc	doc;

	if (fd < 0 || !line || read(fd, b, 0))
		return(-1);
	str = ft_strnew(1);
	while ((r = read(fd, b, BUFF_SIZE)))
	{
		b[r] = '\0';
		tmp = str;
		str = ft_strjoin(str, b);
		free(tmp);
	}
	if (doc.i == 0)
		doc = t_doc_init(fd, str);
	while (doc.lines[doc.i] != NULL)
	{
		*line = doc.lines[doc.i];
		free(doc.lines[doc.i++]);
		return (1);
	}
	if (doc.lines[doc.i] == NULL)
		free(doc.lines);
	return (0);
}
