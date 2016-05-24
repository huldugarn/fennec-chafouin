#include "mlx.h"
#include <stdio.h>

int	ft_exit(int keycode, void *param)
{
	printf("Key event %d\n", keycode);
	return (0);
}

int	main()
{
	void	*parameters;
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	parameters = NULL;
//	mlx_init()
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, ft_exit, parameters);
	mlx_loop(mlx);
}
