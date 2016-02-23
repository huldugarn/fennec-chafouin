/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 09:42:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/23 16:31:31 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_fd(t_list **alst, int fd)
{
	t_list	*cursor;

	cursor = *alst;
	if (cursor)
	{
		while (cursor)
		{
			if (fd == (int)cursor->content_size)
				return (cursor);
			cursor = cursor->next;
		}
	}
	cursor = ft_lstnew("\0", 1);
	cursor->content_size = fd;
	ft_lstpushback(alst, cursor);
	return (cursor);
}

char	*froin_jee(char *content, char *buffer, int r)
{
	char *ptr;

	ptr = content;
	content = ft_strnjoin(content, buffer, r);
	free(ptr);
	return (content);
}

int		get_next_line(int fd, char **line)
{
	char			b[BUFF_SIZE + 1];
	int				r;
	static t_list	*xfd = NULL;
	t_list			*fd_list;
	char			*ptr;

	if (fd < 0 || !line || read(fd, b, 0) < 0)
		return (-1);
	fd_list = xfd;
	xfd = find_fd(&fd_list, fd);
	while (!ft_strchr(xfd->content, '\n') && (r = read(fd, b, BUFF_SIZE)))
		xfd->content = froin_jee(xfd->content, b, r);
	r = 0;
	while (((char *)xfd->content)[r] && ((char *)xfd->content)[r] != '\n')
		++r;
	*line = ft_strndup(xfd->content, r);
	if (((char *)xfd->content)[r] == '\n')
		++r;
	ptr = xfd->content;
	xfd->content = ft_strdup(xfd->content + r);
	free(ptr);
	xfd = fd_list;
	return (r ? 1 : 0);
}
