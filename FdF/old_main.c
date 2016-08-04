#include "fdf.h"
#include <stdio.h>

int	ft_hud(t_param *pm);

int	ft_exit(void *pm_p)
{
	exit(0);
	return (0);
}

int	ft_keycode_functions_index(int keycode, t_param *pm)
{
	printf("Key event %3d\n", keycode);
	if (keycode == 53)
		ft_exit(pm);
	if (keycode == 34)
		ft_hud(pm);
	if (keycode == 35)
		printf("Coordonnées du point stocké dans les paramètres :\n	x = [%i]\n	y = [%i]\n", pm->x, pm->y);
	if (keycode == 49)
		(pm->print == 0) ? (pm->print = 1) : (pm->print = 0);
	return (0);
}

int		key_hook_press(int	keycode, t_param *pm)
{
	if (keycode == 123)
	{
		if (pm->print == 0)
		mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00000000);
		(pm->x > 0 && pm->x <= WIN_W) ? (pm->x--) : (pm->x = pm->x + 0);
		mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00FFFFFF);
	}
	if (keycode == 124)
	{
		if (pm->print == 0)
		mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00000000);
		(pm->x >= 0 && pm->x < WIN_W) ? (pm->x++) : (pm->x = pm->x + 0);
		mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00FFFFFF);
	}
	if (keycode == 125)
	{
		if (pm->print == 0)
		mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00000000);
		(pm->y >= 0 && pm->x < WIN_H) ? (pm->y++) : (pm->y = pm->y + 0);
		mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00FFFFFF);
	}
	if (keycode == 126)
	{
		if (pm->print == 0)
			mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00000000);
		(pm->y > 0 && pm->y <= WIN_H) ? (pm->y--) : (pm->y = pm->y + 0);
		mlx_pixel_put(pm->mlx, pm->win, pm->x, pm->y, 0x00FFFFFF);
	}
	return (0);
}

int	ft_hud(t_param *pm)
{
	int		x;
	int		y;

	x = 5;
	y = 5;
	while (y <= 35)
	{
		while (x <= 210)
		{
			if (y == 5 || y == 35)
				mlx_pixel_put(pm->mlx, pm->win, x, y, 0x00FFFFFF);
			if (x == 5 || x == 210)
				mlx_pixel_put(pm->mlx, pm->win, x, y, 0x00FFFFFF);
			x++;
		}
		x = 5;
		y++;
	}
	mlx_string_put(pm->mlx, pm->win, 15, 10, 0x00007F00, "Press ESC to quit.");
	return (0);
}

t_param	*ft_pm_init(t_param *pm, char *mp)
{
	pm = (t_param*)malloc(sizeof(t_param) * 1);
	pm->mlx = mlx_init();
	pm->win = mlx_new_window(pm->mlx, WIN_W, WIN_H, WIN_N);
	pm->map_path = mp;
	pm->ima = mlx_new_image(pm->mlx, WIN_W, WIN_H);
	pm->ima_data = mlx_get_data_addr(pm->ima, &(pm->ima->bpx), &(pm->ima_szl), &(pm->ima->end));
	pm->grid = create_grid(pm);
	pm->tile_w = TILE_W;
	pm->tile_h = TILE_H;
	pm->x = 100;
	pm->y = 100;
	pm->print = 0;
	return (pm);
}

int	main(int argc, char **argv)

	t_param	*pm;
	t_point	*a;
	t_point	*b;

	a = (t_point*)malloc(sizeof(t_point) * 1);
	b = (t_point*)malloc(sizeof(t_point) * 1);
	a->x = 300;
	a->y = 300;
	b->x = 400;
	b->y = 400;

	pm = ft_pm_init(pm, argv[1]);
//	pm->map_path = argv[1];
//	create_grid(pm);
	
//	draw_line(pm, a, b);
	draw_map(pm);
	mlx_key_hook(pm->win, ft_keycode_functions_index, pm);
	mlx_hook(pm->win, 2, (1L << 0), key_hook_press, pm);
	mlx_hook(pm->win, 17, (1L << 17), &ft_exit, pm);
	mlx_loop(pm->mlx);
	return (0);
}
