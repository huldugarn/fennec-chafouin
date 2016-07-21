/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_calculations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 14:30:39 by rle-corr          #+#    #+#             */
/*   Updated: 2016/07/21 16:21:00 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
void		calculation_full(t_e *e)
{
	int		x;
	int		y;

	y= 0;
	while (y < e->gs_y)
	{
		x = 0;
		while (x < e->gs_x)
		{
			calculation_point(e, &(e->grid[y][x]));
			x++;
		}
		y++;
	}
	draw_map(e);
}

void		calculation_point(t_e *e, t_p *p)
{
	float	display_x;
	float	display_y;
	float	display_z;
	float	__x;
	float	__y;

	display_x = p->x * e->gap_surface;
	display_y = p->y * e->gap_surface;
	display_z = p->z * e->gap_volume;
	__x = display_x * cos(e->angle) - display_y * sin(e->angle);
	__y = display_x * sin(e->angle) - display_y * cos(e->angle);
	p->x_p = __x - __y + WIN_W * 0.3;
	p->y_p = __x * 0.5 + __y * 0.5 - display_z + WIN_H * 0.3;
}

int		display_inclusion(t_e *e, int n, char c)
{
	if (c == 'x' && (n + e->x_move) > 0 && (n + e->x_move) < WIN_W)
		return(1);
	if (c == 'y' && (n + e->y_move) > 0 && (n + e->y_move) < WIN_H)
		return(1);
	return(0);
}

int		translate(t_e *e, int n, char c)
{
	return(c == 'x' ? n + x_translate : n + y_translate);
}
