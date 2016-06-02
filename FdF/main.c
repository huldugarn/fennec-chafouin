#include "fdf.h"
#include <stdio.h>

int	ft_hud(t_param *param);

int	ft_exit(void *param_p)
{
	exit(0);
	return (0);
}

int	ft_keycode_functions_index(int keycode, t_param *param)
{
	printf("Key event %3d\n", keycode);
	if (keycode == 53)
		ft_exit(param);
	if (keycode == 34)
		ft_hud(param);
	if (keycode == 35)
		printf("Coordonnées du point stocké dans les paramètres :\n	x = [%i]\n	y = [%i]\n", param->x, param->y);
	return (0);
}

int		key_hook_press(int	keycode, t_param *param)
{
	if (keycode == 123)
	{
		(param->x > 0 && param->x <= WIN_WIDTH) ? (param->x--) : (param->x = param->x + 0);
		mlx_pixel_put(param->mlx, param->win, param->x, param->y, 0x00FFFFFF);
	}
	if (keycode == 124)
	{
		(param->x >= 0 && param->x < WIN_WIDTH) ? (param->x++) : (param->x = param->x + 0);
		mlx_pixel_put(param->mlx, param->win, param->x, param->y, 0x00FFFFFF);
	}
	if (keycode == 125)
	{
		(param->y >= 0 && param->x < WIN_HEIGHT) ? (param->y++) : (param->y = param->y + 0);
		mlx_pixel_put(param->mlx, param->win, param->x, param->y, 0x00FFFFFF);
	}
	if (keycode == 126)
	{
		(param->y > 0 && param->y <= WIN_HEIGHT) ? (param->y--) : (param->y = param->y + 0);
		mlx_pixel_put(param->mlx, param->win, param->x, param->y, 0x00FFFFFF);
	}
	return (0);
}

int	ft_hud(t_param *param)
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
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
			if (x == 5 || x == 210)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
			x++;
		}
		x = 5;
		y++;
	}
	mlx_string_put(param->mlx, param->win, 15, 10, 0x00007F00, "Press ESC to quit.");
	return (0);
}

t_param	*ft_param_init(t_param *param)
{
	param = (t_param*)malloc(sizeof(t_param) * 1);
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	param->x = 5;
	param->y = 5;
	return (param);
}



int	main()
{
	t_param	*param;

	param = ft_param_init(param);
//	param = (t_param*)malloc(sizeof(t_param) * 1);
//	param->mlx = mlx_init();
//	param->win = mlx_new_window(param->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	mlx_key_hook(param->win, ft_keycode_functions_index, param);
	mlx_hook(param->win, 2, (1L << 0), key_hook_press, param);
	mlx_loop(param->mlx);
}
