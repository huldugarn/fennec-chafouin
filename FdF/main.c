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

int	main()
{
	t_param	*param;

	param = (t_param*)malloc(sizeof(t_param) * 1);
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 700, 400, "mlx 42");
	mlx_key_hook(param->win, ft_keycode_functions_index, param);
	mlx_loop(param->mlx);
}
