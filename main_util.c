#include "cub.h"

/*
	use to set all the usefull data and the start of the program
	*	ft_return_ptr is use like a set and get from any place
	*	or the data need to come from the main or is malloc so
	*	the value is not lost
*/
void	set_main_data(t_cub *cub, t_player *player, t_raycasting *ray)
{
	int	i;

	i = 0;
	ft_bzero(cub, sizeof(t_cub));
	ft_bzero(player, sizeof(t_player));
	ft_bzero(ray, sizeof(t_raycasting));
	ft_return_ptr(cub, e_data);
	while (i < 4)
		cub->wall[i++].img = NULL;
	cub->ray = ray;
	cub->player = player;
	cub->mlx_ft.mlx_destroy_image = &mlx_destroy_image;
	cub->mlx_ft.mlx_get_color_value = &mlx_get_color_value;
	cub->mlx_ft.mlx_get_data_addr = &mlx_get_data_addr;
	cub->mlx_ft.mlx_image_to_window = &mlx_put_image_to_window;
	cub->mlx_ft.mlx_new_image = &mlx_new_image;
	cub->mlx_ft.mlx_xpm_file_to_image = &mlx_xpm_file_to_image;
}

/// @brief setup color for the background
/// @param cub 
void	set_render_data(t_cub *cub)
{
	int32_t		color1;
	int32_t		color2;
	t_texture	*t;

	t = &cub->pars.texture;
	color1 = create_rgb(t->celing[0], t->celing[1], t->celing[2]);
	color2 = create_rgb(t->flore[0], t->flore[1], t->flore[2]);
	cub->ren.color[0] = color1;
	cub->ren.color[1] = color2;
	cub->player->playX = cub->pars.texture.p_x + 0.5;
	cub->player->playY = cub->pars.texture.p_y + 0.5;
	if (cub->pars.texture.p_looking == 'N')
		set_north_south(-1, cub->player);
	else if (cub->pars.texture.p_looking == 'S')
		set_north_south(1, cub->player);
	else if (cub->pars.texture.p_looking == 'E')
		set_east_west(1, cub->player);
	else
		set_east_west(-1, cub->player);
}

t_err	free_wall(t_cub *cub)
{
	short	i;

	i = 0;
	while (i < 4)
	{
		if (cub->wall[i].img)
			cub->mlx_ft.mlx_destroy_image(cub->mlx, &cub->wall[i]);
		cub->wall[i].img = NULL;
		i++;
	}
	return (e_success);
}

static void	print_err(t_err code)
{
	if (code == e_malloc_f)
		ft_printf(2, "Error:\nmalloc fail in import_img, or bad texture name\n");
	if (code == e_bad_size)
		ft_printf(2, "Error:\nsize of image don't fit with define\n");
}

int	import_wall(t_cub *cub)
{
	short		i;
	t_mlx_image	*tmp;
	t_err		err;

	i = 0;
	while (i < 4)
	{
		tmp = &cub->wall[i];
		err = import_img(cub->pars.texture.side[i], cub, tmp);
		if (err < e_success)
		{
			print_err(err);
			return (err);
		}
		i++;
	}
	return (e_success);
}
