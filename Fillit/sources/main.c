/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:28:02 by rle-corr          #+#    #+#             */
/*   Updated: 2016/02/01 19:09:59 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		s;
	int		n;
	int		j;
	char	**tab;
	char	**grid;

	n = 0;
	j = 0;
	if (argc != 2)
		ft_error(0);
	else
		tab = ft_tab(argv[1]);
	while (j == 0)
	{
		grid = ft_grid(tab, n, &s);
		j = ft_resolution(tab, &grid, s, 0);
		n++;
		if (j == 0)
			ft_free(&grid, s);
	}
	ft_display(grid, s);
	return (0);
}

int		ft_resolution(char **tab, char ***grid, int side, int i)
{
	t_coords	tyx;

	if (tab[i] == NULL)
		return (1);
	tyx.y = 0;
	tyx.x = 0;
	ft_coords(&(tyx.ty), tab[i], 0);
	ft_coords(&(tyx.tx), tab[i], 1);
	while (tyx.y < side)
	{
		if (ft_validposition(side, &tyx, grid))
		{
			ft_place(grid, tyx, i, 'A');
			if (ft_resolution(tab, grid, side, (i + 1)))
				return (1);
			else
				ft_place(grid, tyx, 0, '.');
		}
		tyx.x++;
		ft_annex(&tyx, side);
	}
	return (0);
}

void	ft_annex(t_coords *tyx, int side)
{
	if (tyx->x == side)
	{
		tyx->x = 0;
		tyx->y++;
	}
}

void	ft_free(char ***grid, int side)
{
	while (side-- > 0)
	{
		free((*grid)[side]);
	}
	free(*grid);
}
