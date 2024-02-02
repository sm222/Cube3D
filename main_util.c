#include "cub.h"

/*
	use to set all the usefull data and the start of the program
	*	ft_return_ptr is use like a set and get from any place
	*	or the data need to come from the main or is malloc so
	*	the value is not lost
*/
void	set_main_data(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	ft_return_ptr(cub, e_data);
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
}