/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:34:14 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:11 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_doc
{
	int				fd;
	char			**lines;
	int				i;
	struct s_doc	*next;
}					t_doc;

t_doc	t_doc_init(int fd, char *str);
int		get_next_line(int const fd, char **line);

#endif
