/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_1_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:55:48 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/04 16:21:59 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

int		main(int argc, char **argv)
{
	t_e e;

	e.map_path = argv[1];
	if (argc == 2)
	{
		ft_putstr("main_0 OK\n");
		map_processing(&e);
	}
	else
		ft_putstr("No valid map.");
	return (0);
}

void	map_processing(t_e *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, WIN_N);
	e->ima = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->ima_data = mlx_get_data_addr(
			e->ima, &(e->ima_bits), &(e->ima_line), &(e->ima_endi));
	e->grid = create_grid(e);
	reset(e);
	ft_putstr("main_1 OK\n");
	mlx_expose_hook(e->win, hook_expose, e);
	mlx_key_hook(e->win, hook_keys, e);
	mlx_mouse_hook(e->win, hook_mouse, e);
	mlx_loop(e->mlx);
}
