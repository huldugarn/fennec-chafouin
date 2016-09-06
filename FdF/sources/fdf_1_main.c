/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_1_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:55:48 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/11 15:44:48 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_0_header.h"

int		main(int argc, char **argv)
{
	t_e e;

	e.map_path = argv[1];
	if (argc == 2)
		map_processing(&e);
	else
		ft_putstr("An argument(s) related error occured\n");
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
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 17, (1L << 17), &end_exe, e);
	mlx_hook(e->win, 2, (1L << 0), &key_hook_press, e);
	mlx_loop(e->mlx);
}

int		end_exe(t_e *e)
{
	mlx_destroy_image(e->mlx, e->ima);
	mlx_destroy_window(e->mlx, e->win);
	ft_putendl("So long, and thanks for all the fish");
	exit(0);
	return (0);
}
