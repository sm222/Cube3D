/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:11 by edufour           #+#    #+#             */
/*   Updated: 2024/02/13 15:23:10 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"
#include "../render/render.h"

void	jump_dirx(t_raycasting *data)
{
	data->sideDistX += data->deltaDistX;
	data->mapX += data->stepX;
	if (data->stepX > 0)
		data->side = e_we;
	else
		data->side = e_ea;
}

void	jump_diry(t_raycasting *data)
{
	data->sideDistY += data->deltaDistY;
	data->mapY += data->stepY;
	if (data->stepY > 0)
		data->side = e_no;
	else
		data->side = e_so;
}

void	calculate_wall_height(t_raycasting *data, t_cub *cub)
{
	if (data->side == e_no || data->side == e_so)
		data->wallX = cub->player->playX
			+ data->perpWallDist * data->rayDirX;
	else
		data->wallX = cub->player->playY
			+ data->perpWallDist * data->rayDirY;
	data->wallX -= floor(data->wallX);
	data->texX = (int)(data->wallX * IMAGE_S);
	if (data->side == e_ea || data->side == e_we)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = (WIN_H / data->perpWallDist);
	data->drawStart = (data->lineHeight * -1) / 2 + WIN_H / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + WIN_H / 2;
	if (data->drawEnd >= WIN_H)
		data->drawEnd = WIN_H - 1;
}

void	draw_vertical_line(t_cub *cub, t_raycasting *data, int x)
{
	int		y;

	y = data->drawStart;
	data->step = 1.0 * IMAGE_S / data->lineHeight;
	data->texPos = (data->drawStart - WIN_H / 2 + data->lineHeight / 2)
		* data->step;
	if (y >= data->drawEnd)
	{
		y = WIN_H / 2 - 10;
		data->drawEnd = WIN_H / 2 + 10;
	}
	while (y < data->drawEnd)
	{
		data->texY = (int)data->texPos & (IMAGE_S -1);
		if (data->texY >= IMAGE_S)
			data->texY &= (IMAGE_S - 1);
		data->texPos += data->step;
		data->color = return_color_from_image(&(cub->wall[data->side]),
				data->texX, data->texY);
		render_pixel_to_img(data->color, &(cub->ren.frame), x, y);
		y++;
	}
}

// returns a pointer to an image(draws on the image) (either draws directly on
// and returns the pointer given as argument or creates a copy and returns it)
void	*raycaster(t_cub *cub, t_raycasting *data)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		init_raydata(x, data, cub->player);
		while (data->hit == 0)
		{
			if (data->sideDistX < data->sideDistY)
				jump_dirx(data);
			else
				jump_diry(data);
			if (cub->map[data->mapY][data->mapX] == '1')
				data->hit = 1;
		}
		data->hit = 0;
		calculate_wall_height(data, cub);
		draw_vertical_line(cub, data, x);
		x++;
	}
	return (NULL);
}
