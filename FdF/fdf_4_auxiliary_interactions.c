/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_4_auxiliary_interactions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:01:23 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/11 16:18:19 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

void	zoom(t_e *e, int order)
{
	if (order == IN___)
		e->gap_surface += 1;
	if (order == OUT__)
		e->gap_surface -= 1;
	expose_hook_reset(e);
}

void	translation(t_e *e, int order)
{
	if (order == UP___)
		e->y_translate += 20;
	if (order == DOWN_)
		e->y_translate -= 20;
	if (order == LEFT_)
		e->x_translate += 20;
	if (order == RIGHT)
		e->x_translate -= 20;
	expose_hook_reset(e);
}

void	rotation(t_e *e, int order)
{
	if (order == LEFT_)
		e->angle -= 0.05;
	if (order == RIGHT)
		e->angle += 0.05;
	expose_hook_reset(e);
}

void	extrusion(t_e *e, char order)
{
	if (order == MORE_)
		e->gap_volume += (e->gap_volume + 1 > 50) ? 0 : 1;
	if (order == LESS_)
		e->gap_volume -= (e->gap_volume - 1 < 0) ? 0 : 1;
	expose_hook_reset(e);
}

void	reset(t_e *e)
{
	e->gap_surface = 20;
	e->gap_volume = 3;
	e->angle = 0;
	e->x_translate = 70;
	e->y_translate = 1;
	expose_hook_reset(e);
}
