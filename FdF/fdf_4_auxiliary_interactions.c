/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_4_auxiliary_interactions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:01:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/04 16:01:35 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

void	zoom(t_e *e, int order)
{
	if (order == IN___)
		e->gap_surface += 1;
	if (order == OUT__)
		e->gap_surface -= 1;
	hook_expose_reset(e);
}

void	translation(t_e *e, int order)
{
	if (order == UP___)
		e->y_translate -= 10;
	if (order == DOWN_)
		e->y_translate += 10;
	if (order == LEFT_)
		e->x_translate -= 10;
	if (order == RIGHT)
		e->x_translate += 10;
	hook_expose_reset(e);
}

void	rotation(t_e *e, int order)
{
	if (order == LEFT_)
		e->angle -= 0.05;
	if (order == RIGHT)
		e->angle += 0.05;
	hook_expose_reset(e);
}

void	extrusion(t_e *e, char order)
{
	if (order == MORE_)
		e->gap_volume = (e->gap_volume + 1.2 <= 0) ?
			e->gap_volume : e->gap_volume + 1.2;
	if (order == LESS_)
		e->gap_volume = (e->gap_volume - 1.2 <= 0) ?
			e->gap_volume : e->gap_volume - 1.2;
	hook_expose_reset(e);
}

void	reset(t_e *e)
{
	e->gap_surface = 20;
	e->gap_volume = 5;
	e->angle = 0;
	e->x_translate = 1;
	e->y_translate = 1;
	hook_expose_reset(e);
}
