#include "cub.h"

int	exit_window(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->ren.frame.img);
	mlx_destroy_window(cub->mlx, cub->window);
	cub->map = (t_map)ft_double_sfree((void **)cub->map);
	clean_wall_name(&cub->pars);
	cub->mlx = ft_free(cub->mlx);	//* add the free of mlx ptr
	ft_printf(2, "%oexit\n", NULL);
	exit(0); //you need it ;)
	return (0);
}

void	mlx_fail_omg(t_cub *cub)
{
	clean_wall_name(&cub->pars);
	cub->map = (t_map)ft_double_sfree((void **)cub->map);
	if (cub->ren.frame.img)
		mlx_destroy_image(cub->mlx, cub->ren.frame.img);
	if (!cub->mlx)
	{
		ft_printf(2, "%oError:\nmlx_init fail\n", NULL);
		exit(1);
	}
	cub->mlx = ft_free(cub->mlx);
	ft_printf(2, "%oError:\nmlx_new_window fail\n", NULL);
	exit(1);
}

void	free_no_exit(t_cub *cub)
{
	if (cub->mlx && cub->ren.frame.img)
	{
		mlx_destroy_image(cub->mlx, cub->ren.frame.img);
		cub->ren.frame.img = NULL;
	}
	if (cub->mlx && cub->window)
	{
		mlx_destroy_window(cub->mlx, cub->window);
		cub->window = NULL;
	}
	cub->map = (t_map)ft_double_sfree((void **)cub->map);
	clean_wall_name(&cub->pars);
	free_wall(cub);
	cub->mlx = ft_free(cub->mlx);
}