/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:11 by edufour           #+#    #+#             */
/*   Updated: 2024/02/14 11:29:53 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"
#include "../render/render.h"
#include "../include/structure.h"

void	jump_dirx(t_raycasting *data)
{
	data->sidedistx += data->deltadistx;
	data->mapx += data->stepx;
	if (data->stepx > 0)
		data->side = e_we;
	else
		data->side = e_ea;
}

void	jump_diry(t_raycasting *data)
{
	data->sidedisty += data->deltadisty;
	data->mapy += data->stepy;
	if (data->stepy > 0)
		data->side = e_no;
	else
		data->side = e_so;
}

void	calculate_wall_height(t_raycasting *data, t_cub *cub)
{
	if (data->side == e_no || data->side == e_so)
		data->wallx = cub->player->playx
			+ data->perpwalldist * data->raydirx;
	else
		data->wallx = cub->player->playy
			+ data->perpwalldist * data->raydiry;
	data->wallx -= floor(data->wallx);
	data->texx = (int)(data->wallx * IMAGE_S);
	if (data->side == e_ea || data->side == e_we)
		data->perpwalldist = (data->sidedistx - data->deltadistx);
	else
		data->perpwalldist = (data->sidedisty - data->deltadisty);
	data->lineheight = (WIN_H / data->perpwalldist);
	data->drawstart = (data->lineheight * -1) / 2 + WIN_H / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + WIN_H / 2;
	if (data->drawend >= WIN_H)
		data->drawend = WIN_H - 1;
}

void	draw_vertical_line(t_cub *cub, t_raycasting *data, int x)
{
	int		y;

	y = data->drawstart;
	data->step = 1.0 * IMAGE_S / data->lineheight;
	data->texpos = (data->drawstart - WIN_H / 2 + data->lineheight / 2)
		* data->step;
	if (y >= data->drawend)
	{
		y = WIN_H / 2 - 10;
		data->drawend = WIN_H / 2 + 10;
	}
	while (y < data->drawend)
	{
		data->texy = (int)data->texpos & (IMAGE_S -1);
		if (data->texy >= IMAGE_S)
			data->texy &= (IMAGE_S - 1);
		data->texpos += data->step;
		data->color = return_color_from_image(&(cub->wall[data->side]),
				data->texx, data->texy);
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
			if (data->sidedistx < data->sidedisty)
				jump_dirx(data);
			else
				jump_diry(data);
			if (cub->map[data->mapy][data->mapx] == '1')
				data->hit = 1;
		}
		data->hit = 0;
		calculate_wall_height(data, cub);
		draw_vertical_line(cub, data, x);
		x++;
	}
	return (NULL);
}
