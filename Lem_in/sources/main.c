/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:09:24 by rle-corr          #+#    #+#             */
/*   Updated: 2017/01/17 12:09:31 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		initialize(t_lmn *s)
{
	if (!(s->fd = open("log", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR)))
		return (0);
	s->n_ants = -1;
	s->n_rooms = -1;
	s->c_rooms = 0;
	s->n_links = -1;
	s->buffer = NULL;
	s->record = NULL;
	s->s_room = NULL;
	s->e_room = NULL;
	s->rooms = NULL;
	printf("initialize		> OK\n");
	return (1);
}
/*
void			filler_board_print(t_grd *grid, t_flr *fsp)
{
	int			i;

	i = 0;
	while (i < grid->h)
	{
		ft_putstr_fd("	", fsp->fd);
		ft_putnbr_fd(i, fsp->fd);
		ft_putstr_fd("	", fsp->fd);
		ft_putendl_fd(grid->data[i], fsp->fd);
		++i;
	}
}

void			filler_piece_print(t_grd *grid, t_flr *fsp)
{
	int			i;

	i = 0;
	ft_putstr_fd("	up_p = [", fsp->fd);
	ft_putnbr_fd(grid->up_p, fsp->fd);
	ft_putstr_fd("]	", fsp->fd);
	ft_putstr_fd("lo_p = [", fsp->fd);
	ft_putnbr_fd(grid->lo_p, fsp->fd);
	ft_putstr_fd("]	", fsp->fd);
	ft_putstr_fd("le_p = [", fsp->fd);
	ft_putnbr_fd(grid->le_p, fsp->fd);
	ft_putstr_fd("]	", fsp->fd);
	ft_putstr_fd("ri_p = [", fsp->fd);
	ft_putnbr_fd(grid->ri_p, fsp->fd);
	ft_putendl_fd("]", fsp->fd);
	while (i < grid->h)
	{
		ft_putstr_fd("	", fsp->fd);
		ft_putnbr_fd(i, fsp->fd);
		ft_putstr_fd("	", fsp->fd);
		ft_putendl_fd(grid->data[i], fsp->fd);
		++i;
	}
}

void			filler_grid_free(t_grd *grid)
{
	int			x;

	x = -1;
	while (grid->data[++x] != '\0')
		free(grid->data[x]);
	grid = NULL;
}
*/
int				main(void)
{
	t_lmn		lem_in_structure;

	printf("_____________________________________________\n");
	if (!initialize(&lem_in_structure))
	{
		ft_putendl("Lem_in structure initializing error");
		return (0);
	}
	lem_in_read(&lem_in_structure);
//	lem_in_play(&lem_in_structure);
}
