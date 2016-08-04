/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_5_auxiliary_calculations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:02:08 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/04 16:02:22 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

void		calculation_full(t_e *e)
{
	int		x;
	int		y;

	y = 0;
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
	draw_full(e);
}

void		calculation_point(t_e *e, t_p *p)
{
	float	display_x;
	float	display_y;
	float	display_z;
	float	s_x;
	float	s_y;

	display_x = p->x * e->gap_surface;
	display_y = p->y * e->gap_surface;
	display_z = p->z * e->gap_volume;
	s_x = display_x * cos(e->angle) - display_y * sin(e->angle);
	s_y = display_x * sin(e->angle) - display_y * cos(e->angle);
	p->x_p = s_x - s_y + WIN_W * 0.3;
	p->y_p = s_x * 0.5 + s_y * 0.5 - display_z + WIN_H * 0.3;
}

int			display_inclusion(t_e *e, int n, char c)
{
	if (c == 'x' && (n + e->x_translate) > 0 && (n + e->x_translate) < WIN_W)
		return (1);
	if (c == 'y' && (n + e->y_translate) > 0 && (n + e->y_translate) < WIN_H)
		return (1);
	return (0);
}

int			translate(t_e *e, int n, char c)
{
	return (c == 'x' ? n + e->x_translate : n + e->y_translate);
}
