#include "include/structure.h"
#include "lib/minilibx_opengl_20191021/mlx.h"

int	exit_window(t_parsing *info)
{
	mlx_destroy_window(info->mlx, info->window);
	return (0);
}

int	keybinds(int keycode, t_parsing *info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->window);
		// exit_free(info);
	}
	return (0);
}

/*The "param" argument in mlx functions represents the argument 
taken by the preceding function argument.*/
int	main(void)
{
	t_parsing *info = malloc(sizeof(t_parsing));
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, 10 * 64, 10 * 64, "test");

	mlx_key_hook(info->window, keybinds, info);
	mlx_hook(info->window, 17, 0, exit_window, info);
	mlx_loop(info->mlx);
}