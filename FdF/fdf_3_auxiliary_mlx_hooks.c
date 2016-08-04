/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3_auxiliary_mlx_hooks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:59:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/04 16:54:50 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

int		hook_expose(t_e *e)
{
	calculation_full(e);
	mlx_put_image_to_window(e->mlx, e->win, e->ima, 0, 0);
//	fonction pour afficher des infos à l'écran
	return (0);
}

void	hook_expose_reset(t_e *e)
{
	ft_bzero(e->ima_data, WIN_W * WIN_H * 4);
	hook_expose(e);
}

int		hook_keys(t_e *e, int key)
{
	if (key == NP_5 || key == NP_0 || key == PG_U || key == PG_D)
		(key == NP_5 || key == PG_U) ? zoom(e, IN___) : zoom(e, OUT__);
	if (key == NP_8 || key == AR_U)
		translation(e, UP___);
	if (key == NP_2 || key == AR_D)
		translation(e, DOWN_);
	if (key == NP_4 || key == NP_6)
		key == NP_4 ? translation(e, LEFT_) : translation(e, RIGHT);
	if (key == NP_4 || key == NP_6)
		key == NP_4 ? rotation(e, LEFT_) : rotation(e, RIGHT);
	if (key == NP_PLUS || key == NP_MINUS)
		key == NP_PLUS ? extrusion(e, MORE_) : extrusion(e, LESS_);
	return (0);
}

int		hook_mouse(t_e *e, int button, int x, int y)
{
	return (0);
}
