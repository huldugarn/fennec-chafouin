/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:56:34 by rle-corr          #+#    #+#             */
/*   Updated: 2017/01/17 11:56:37 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		if_op_add_one(t_flr *s, int x, int y, char p)
{
	return (s->brd->data[x][y] == p || s->brd->data[x][y] == p + 40 ? 1 : 0);
}

static int		lookaround(t_flr *s, int ax, int ay, char p)
{
	int			x;
	int			y;
	int			n;

	n = 0;
	x = -2;
	while (++x < 2)
	{
		y = -2;
		while (++y < 2)
		{
			if (ax + x >= 0 && ax + x < s->brd->h - 1 &&
				ay + y >= 0 && ay + y < s->brd->w - 1)
			{
				n += if_op_add_one(s, ax + x, ay + y, p);
			}
		}
	}
	return (n);
}

static	int		contact_note(t_flr *s)
{
	t_coords	t;
	char		p;
	int			n;

	n = 0;
	p = s->pawn == 'O' ? 'X' : 'O';
	t.x = -1;
	while (++t.x < s->pce->h)
	{
		t.y = -1;
		while (++t.y < s->pce->w)
		{
			if (s->pce->data[t.x][t.y] == '*')
			{
				n += lookaround(s, s->brd->p.x + t.x, s->brd->p.y + t.y, p);
			}
		}
	}
	return (n);
}

static	int		position_note(t_flr *s)
{
	int			a_x;
	int			a_y;
	int			c_x;
	int			c_y;

	c_x = (s->pce->up_p + ((s->pce->h + 1) - s->pce->lo_p)) / 2;
	c_y = (s->pce->le_p + ((s->pce->w + 1) - s->pce->ri_p)) / 2;
	a_x = ft_absolu((s->brd->p.x + (c_x)) - (s->brd->h / 2));
	a_y = ft_absolu((s->brd->p.y + (c_y)) - (s->brd->w / 2));
	return (a_x + a_y);
}

void			filler_note(t_flr *s)
{
	s->brd->p.n = position_note(s);
	s->brd->p.c = contact_note(s);
	if (s->best.n == -1)
		s->best = s->brd->p;
	else if (s->brd->p.c == 0 && s->best.c == 0)
		s->best = (s->brd->p.n < s->best.n ? s->brd->p : s->best);
	else if (s->brd->p.c > 0)
	{
		if (s->best.c == 0)
			s->best = s->brd->p;
		else if (s->brd->p.c <= s->best.c)
			s->best = (s->brd->p.n < s->best.n ? s->brd->p : s->best);
	}
}
