#include "render.h"

static void	set_back_ground(t_render *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			render_pixel_to_img(data->color[0], &data->frame, x, y);
			x++;
		}
		y++;
	}
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			render_pixel_to_img(data->color[1], &data->frame, x, y);
			x++;
		}
		y++;
	}
}

static void	render_image(t_render *data, t_cub *cub)
{
	t_mlx_ft	*ft;

	if (!data || !cub)
	{
		ft_printf(2, "%o"RED"WARNING: render_image missing data\n", NULL);
		return ;
	}
	ft = &cub->mlx_ft;
	ft->mlx_image_to_window(cub->mlx, cub->window, data->frame.img, 0, 0);
}

int	render(t_cub *data, short mode)
{
	if (mode == e_clean)
		set_back_ground(&data->ren);
	if (mode == e_render)
		render_image(&data->ren, data);
	return (0);
}