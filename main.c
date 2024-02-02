#include "cub.h"

int	exit_window(t_cub *info)
{
	(void)info;
	mlx_destroy_window(info->mlx, info->window);
	exit(0); //you need it ;)
	return (0);
}

int	keybinds(int keycode, t_cub *info)
{
	ft_printf(2, "key press = %d\n", keycode);
	if (keycode == 53)
		exit_window(info);
	return (0);
}

/// @brief call the pipeline of rendering
/// @param cub 
/// @return 
int	call_render(t_cub *cub)
{
	render(cub, e_clean);
	raycaster(cub);
	render(cub, e_render);
	return (0);
}

/*
/The "param" argument in mlx functions represents the argument 
taken by the preceding function argument./
*/
int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac < 2 || ac > 2)
		return (bad_args_main(ac));
	set_main_data(&cub);
	if (!parsing(av[1], &cub))
		return (1);
	set_render_data(&cub);
	debug(cub); //! free all parsing in here remove for more test
	cub.mlx = mlx_init();
	cub.window = mlx_new_window(cub.mlx, WIN_W, WIN_H, "test"); //? can add a name for later in a define
	make_mlx_image(&cub.ren.frame, &cub);
	mlx_key_hook(cub.window, keybinds, &cub);
	mlx_hook(cub.window, 17, 0, exit_window, &cub);
	mlx_loop_hook(cub.mlx, &call_render, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
