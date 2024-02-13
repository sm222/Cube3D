#include "cub.h"

/// @brief call the pipeline of rendering
/// @param cub 
/// @return 
int	call_render(t_cub *cub)
{
	(void) render(cub, e_clean);
	raycaster(cub, cub->ray);
	(void) render(cub, e_render);
	return (0);
}

static	void set_name_window(t_cub *cub, char *name)
{
	size_t	i;
	size_t	j;

	i = 8;
	j = 0;
	ft_memcpy(name, "Cub3D - ", 8);
	while (cub->pars.map_name && cub->pars.map_name[j] && i < 99)
	{
		name[i] = cub->pars.map_name[j];
		i++;
		j++;
	}
}

static t_err	start_game(t_cub *cub)
{
	char	name_win[100];

	ft_bzero(name_win, sizeof(char) * 100);
	set_name_window(cub, name_win);
	if (make_mlx_image(&cub->ren.frame, cub) < e_success)
	{
		free_no_exit(cub);
		ft_printf(2, "Error:\nmalloc fail\n");
		return (e_fail);
	}
	if (import_wall(cub) < e_success)
	{
		free_no_exit(cub);
		return (e_fail);
	}
	cub->window = mlx_new_window(cub->mlx, WIN_W, WIN_H, name_win);
	if (!cub->window)
		mlx_fail_omg(cub);
	return (e_success);
}


/*
/The "param" argument in mlx functions represents the argument 
taken by the preceding function argument./
*/
int	main(int ac, char **av)
{
	t_cub			cub;
	t_player		player;
	t_raycasting	ray;

	if (ac < 2 || ac > 2)
		return (bad_args_main(ac));
	set_main_data(&cub, &player, &ray);
	if (!parsing(av[1], &cub))
	{
		free_no_exit(&cub);
		return (1);
	}
	set_render_data(&cub);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		mlx_fail_omg(&cub);
	if (start_game(&cub) < e_success)
		exit(1);
	mlx_key_hook(cub.window, keybinds, &cub);
	mlx_hook(cub.window, 17, 0, exit_window, &cub);
	mlx_loop_hook(cub.mlx, &call_render, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
