/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3_auxiliary_mlx_hooks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:59:38 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/11 15:52:34 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

int		expose_hook(t_e *e)
{
	calculation_full(e);
	mlx_put_image_to_window(e->mlx, e->win, e->ima, 0, 0);
	return (0);
}

void	expose_hook_reset(t_e *e)
{
	ft_bzero(e->ima_data, WIN_W * WIN_H * 4);
	expose_hook(e);
}

int		key_hook(int keycode, t_e *e)
{
	if (keycode == KB_ESC)
		end_exe(e);
	if (keycode == NP_DOT)
		reset(e);
	return (0);
}

int		key_hook_press(int keycode, t_e *e)
{
	if (keycode == NP_5 || keycode == PG_U)
		zoom(e, IN___);
	if (keycode == NP_0 || keycode == PG_D)
		zoom(e, OUT__);
	if (keycode == NP_8 || keycode == AR_U)
		translation(e, UP___);
	if (keycode == NP_2 || keycode == AR_D)
		translation(e, DOWN_);
	if (keycode == NP_4 || keycode == AR_L)
		translation(e, LEFT_);
	if (keycode == NP_6 || keycode == AR_R)
		translation(e, RIGHT);
	if (keycode == NP_7)
		rotation(e, LEFT_);
	if (keycode == NP_9)
		rotation(e, RIGHT);
	if (keycode == NP_PLUS || keycode == NP_MINUS)
		keycode == NP_PLUS ? extrusion(e, MORE_) : extrusion(e, LESS_);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_e *e)
{
	return (0);
}
