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
			data->image[y][x] = data->color[0];
			x++;
		}
		y++;
	}
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			data->image[y][x] = data->color[1];
			x++;
		}
		y++;
	}
}

static void	clean_image(t_render *data)
{
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		ft_bzero(data->image[y], sizeof(int) * WIN_W);
		y++;
	}
	set_back_ground(data);
}

static int	add_layer(t_render *data, int **layer)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (layer[y][x])
				data->image[y][x] = layer[y][x];
			x++;
		}
		y++;
	}
	return (0);
}

void	render_img(t_render *data, t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			data->render(cub->mlx, cub->window, x, y, data->image[y][x]);
			x++;
		}
		y++;
	}
}

int	render(t_cub *data, short mode, int **layer)
{
	if (mode == e_clean)
		clean_image(&data->ren);
	if (mode == e_add_l && layer)
		add_layer(&data->ren, layer);
	if (mode == e_render)
		render_img(&data->ren, data);
	return (0);
}