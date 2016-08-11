/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_6_auxiliary_drawing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:02:53 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/11 16:27:10 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

void	draw_full(t_e *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H && y < e->gs_y)
	{
		x = 0;
		while (x < WIN_W && x < e->gs_x)
		{
			if (x < e->gs_x - 1)
				draw_line(e, &(e->grid[y][x]), &(e->grid[y][x + 1]));
			if (y < e->gs_y - 1)
				draw_line(e, &(e->grid[y][x]), &(e->grid[y + 1][x]));
			++x;
		}
		++y;
	}
}

void	draw_line(t_e *e, t_p *a, t_p *b)
{
	t_b	*bsh;
	t_p	p;
	int	delta_error;

	bsh = bresenham_init(a, b, e->z_max, e->gap_volume);
	p.x = a->x_p;
	p.y = a->y_p;
	while (1)
	{
		if (display_inclusion(e, p.x, 'x') && display_inclusion(e, p.y, 'y'))
			draw_pixl(e, translate(e, p.x, 'x'), translate(e, p.y, 'y'),
					a->color);
		if (p.x == b->x_p && p.y == b->y_p)
			break;
		if ((delta_error = bsh->delta_error) > -(bsh->delta_x))
		{
			bsh->delta_error -= bsh->delta_y;
			p.x += bsh->sign_x;
		}
		if (delta_error < bsh->delta_y)
		{
			bsh->delta_error += bsh->delta_x;
			p.y += bsh->sign_y;
		}
	}
	free(bsh);
}

void	draw_pixl(t_e *e, int x, int y, int color)
{
	ft_memcpy(&e->ima_data[(x * 4) + (y * e->ima_line)], &(color),
			(size_t)(sizeof(int)));
}

t_b		*bresenham_init(t_p *a, t_p *b, int z_max, int volume)
{
	t_b	*bsh;

	bsh = (t_b *)malloc(sizeof(t_b));
	bsh->delta_x = ft_absolu(b->x_p - a->x_p);
	bsh->delta_y = ft_absolu(b->y_p - a->y_p);
	bsh->delta_error = (bsh->delta_x > bsh->delta_y ?
			bsh->delta_x : -(bsh->delta_y)) / 2;
	bsh->sign_x = a->x_p < b->x_p ? 1 : -1;
	bsh->sign_y = a->y_p < b->y_p ? 1 : -1;
	a->color = color_selection(a->z, b->z, z_max, volume);
	return(bsh);
}

int		color_selection(int a_z, int b_z, int z_max, int volume)
{
	int	z_med;

	z_med = (a_z + b_z) / 2;
	if (z_med > z_max * 0.8)
		return(WHT);
	else if (z_med == 0)
		return(MRN);
	else if (z_med < 0)
		return(BLU);
	return(GRN);
}
