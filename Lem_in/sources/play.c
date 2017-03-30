/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:09:58 by rle-corr          #+#    #+#             */
/*   Updated: 2017/01/17 12:10:05 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		put_coords(int x, int y, t_flr *fsp)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
	ft_putstr_fd("VALIDE EN :", fsp->fd);
	ft_putnbr_fd(x, fsp->fd);
	ft_putchar_fd(' ', fsp->fd);
	ft_putnbr_fd(y, fsp->fd);
	ft_putendl_fd(" !!", fsp->fd);
	++(fsp->turn);
}

static int		part_overlap_pawn(t_grd *board, t_coords pos, int p_nb)
{
	if (p_nb == 1 || p_nb == 3)
	{
		if (board->data[pos.x][pos.y] == 'O')
			return (1);
		if (board->data[pos.x][pos.y] == 'o')
			return (1);
	}
	if (p_nb == 2 || p_nb == 3)
	{
		if (board->data[pos.x][pos.y] == 'X')
			return (1);
		if (board->data[pos.x][pos.y] == 'x')
			return (1);
	}
	return (0);
}

static int		invalid_part(t_coords p, t_grd *b, t_flr *fsp, int *o)
{
	if (p.x >= b->h || p.y >= b->w)
		return (1);
	else if (!*o && part_overlap_pawn(b, p, fsp->p_nb))
		*o = 1;
	else if (*o && part_overlap_pawn(b, p, fsp->p_nb))
		return (1);
	else if (part_overlap_pawn(b, p, 3))
		return (1);
	return (0);
}

static int		valid_piece(t_flr *fsp)
{
	int			overlap;
	t_coords	tmp_p;

	overlap = 0;
	fsp->pce->p.x = -1;
	while (fsp->pce->data[++fsp->pce->p.x])
	{
		fsp->pce->p.y = -1;
		while (fsp->pce->data[fsp->pce->p.x][++fsp->pce->p.y])
		{
			if (fsp->pce->data[fsp->pce->p.x][fsp->pce->p.y] == '*')
			{
				tmp_p.x = fsp->brd->p.x + fsp->pce->p.x;
				tmp_p.y = fsp->brd->p.y + fsp->pce->p.y;
				if (invalid_part(tmp_p, fsp->brd, fsp, &overlap))
					return (0);
			}
		}
	}
	if (!overlap || fsp->brd->p.x + fsp->pce->h > fsp->brd->h
		|| fsp->brd->p.y + fsp->pce->w > fsp->brd->w)
		return (0);
	return (1);
}

void			filler_play(t_flr *s)
{
	s->best.x = 0;
	s->best.y = 0;
	s->best.n = -1;
	s->best.c = 0;
	filler_board_print(s->brd, s);
	filler_piece_print(s->pce, s);
	s->brd->p.x = -1;
	while (++s->brd->p.x + s->pce->up_p < s->brd->h - s->pce->lo_p)
	{
		s->brd->p.y = -1;
		while (++s->brd->p.y + s->pce->le_p < s->brd->w - s->pce->ri_p)
		{
			if (valid_piece(s))
				filler_note(s);
		}
	}
	if (s->best.n != -1)
	{
		put_coords(s->best.x, s->best.y, s);
		return ;
	}
	put_coords(0, 0, s);
}
