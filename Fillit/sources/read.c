/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:36:17 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/01 19:23:04 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include "../libft/libft.h"

int			ft_tetracontrol(char *tetra)
{
	int		i;
	int		nb;
	int		nss;

	i = 0;
	nb = 0;
	nss = 0;
	while (tetra[i++] != '\0')
		if (tetra[i] == XF)
		{
			nb++;
			if (i > 4 && tetra[i - 4] == XF)
				nss++;
			if (i > 1 && tetra[i - 1] == XF)
				nss++;
			if (i < 16 && tetra[i + 1] == XF)
				nss++;
			if (i < 13 && tetra[i + 4] == XF)
				nss++;
		}
	if (nb == 4 && (nss == 6 || nss == 8))
		return (1);
	return (0);
}

char		*ft_line(char *buffer)
{
	char	*line;
	int		il;
	int		ib;

	il = 0;
	ib = 0;
	if (!(line = (char*)ft_memalloc(18)))
		ft_error(0);
	line[il++] = '?';
	while (buffer[ib] != '\0')
	{
		buffer[ib] == '\n' ? ib++ : (line[il++] = buffer[ib++]);
	}
	if (ft_tetracontrol(line) == 1)
		return (line);
	ft_error(0);
	return (NULL);
}

int			ft_gridcontrol(char *buffer, int rr)
{
	int		i;
	int		nl;

	i = 0;
	nl = 4;
	if (buffer[20] != '\n' && rr == 21)
		ft_error(0);
	while (i < 20)
	{
		if (i < nl && (buffer[i] == XF || buffer[i] == XE))
			i++;
		else if (i == nl && buffer[nl] == '\n')
		{
			i++;
			nl += 5;
		}
		else
			ft_error(0);
	}
	return (1);
}

char		*ft_read(int fd, int *s_rr)
{
	int		rr;
	char	buffer[22];
	char	*line;

	line = NULL;
	if ((rr = read(fd, buffer, 21)))
	{
		buffer[rr] = '\0';
		if (ft_gridcontrol(buffer, rr) == 1)
			line = ft_line(buffer);
		else
			ft_error(0);
	}
	if ((*s_rr == 21 && rr != 21) && (*s_rr == 21 && rr != 20))
		ft_error(0);
	*s_rr = rr;
	if (rr == -1)
		ft_error(0);
	return (line);
}

char		**ft_tab(char *file)
{
	int		fd;
	char	**tab;
	int		i;
	int		s_rr;

	s_rr = 0;
	i = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * 27)))
		ft_error(0);
	while (i++ < 27)
		tab[i] = NULL;
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(0);
	while ((tab[i] = ft_read(fd, &s_rr)))
	{
		if (i == 26)
			ft_error(0);
		tab[i][0] = 'A' + i;
		i++;
		tab[i] = NULL;
	}
	if (close(fd) == -1 || i == 0)
		ft_error(0);
	return (tab);
}
