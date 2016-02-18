/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:37:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/31 18:24:40 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

char	**ft_grid(char **tab, int n, int *s)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	while (tab[i] != '\0')
		i++;
	*s = ft_squareroot(i * 4) + n;
	if (!(grid = (char **)ft_memalloc(sizeof(char *) * *s + 1)))
		ft_error(7);
	i = 0;
	while (i < *s)
	{
		j = 0;
		if (!(grid[i] = (char *)ft_memalloc(sizeof(char) * *s + 1)))
			ft_error(7);
		while (j < *s)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

void	ft_coords(int (*tyx)[4], char *line, int opt)
{
	int	l;
	int	t;

	l = 1;
	t = 0;
	(*tyx)[0] = 0;
	while (line[l] != '\0')
	{
		if (line[l] == XF)
		{
			if (opt == 0)
				(*tyx)[t++] = (l - 1) / 4 - (*tyx)[0];
			else
				(*tyx)[t++] = (l - 1) % 4 - (*tyx)[0];
		}
		l++;
	}
	(*tyx)[0] = 0;
}

int		ft_validposition(int side, t_coords *tyx, char ***grid)
{
	if ((tyx->tx)[1] + tyx->x >= 0 && (tyx->tx)[1] + tyx->x < side && \
		(tyx->ty)[1] + tyx->y >= 0 && (tyx->ty)[1] + tyx->y < side && \
		(tyx->tx)[2] + tyx->x >= 0 && (tyx->tx)[2] + tyx->x < side && \
		(tyx->ty)[2] + tyx->y >= 0 && (tyx->ty)[2] + tyx->y < side && \
		(tyx->tx)[3] + tyx->x >= 0 && (tyx->tx)[3] + tyx->x < side && \
		(tyx->ty)[3] + tyx->y >= 0 && (tyx->ty)[3] + tyx->y < side)
		if ((*grid)[tyx->y][tyx->x] == XE && \
			(*grid)[(tyx->ty)[1] + tyx->y][(tyx->tx)[1] + tyx->x] == XE && \
			(*grid)[(tyx->ty)[2] + tyx->y][(tyx->tx)[2] + tyx->x] == XE && \
			(*grid)[(tyx->ty)[3] + tyx->y][(tyx->tx)[3] + tyx->x] == XE)
		{
			return (1);
		}
	return (0);
}

void	ft_place(char ***grid, t_coords tyx, int i, char c)
{
	int j;

	j = 0;
	while (j < 4)
	{
		(*grid)[(tyx.ty)[j] + tyx.y][(tyx.tx)[j] + tyx.x] = c + i;
		j++;
	}
}
