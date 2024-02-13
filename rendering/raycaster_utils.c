/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:19:05 by edufour           #+#    #+#             */
/*   Updated: 2024/02/13 15:23:06 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/raycast.h"

void	set_north_south(double dir, t_player *vectors)
{
	vectors->dirX = 0;
	vectors->dirY = dir;
	vectors->planeX = vectors->dirY * (-(double)FOV / 100);
	vectors->planeY = vectors->dirX * ((double)FOV / 100);
}

void	set_east_west(double dir, t_player *vectors)
{
	vectors->dirX = dir;
	vectors->dirY = 0;
	vectors->planeX = vectors->dirY * (-(double)FOV / 100);
	vectors->planeY = vectors->dirX * ((double)FOV / 100);
}

void	set_raydir(t_raycasting *data, t_player *player)
{
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (player->playX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - player->playX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (player->playY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - player->playY) * data->deltaDistY;
	}
}

void	init_raydata(int x, t_raycasting *data, t_player *player)
{
	data->mapX = player->playX;
	data->mapY = player->playY;
	data->cameraX = ((2 * x) / (double)WIN_W) - 1;
	data->rayDirX = player->dirX + (player->planeX * data->cameraX);
	data->rayDirY = player->dirY + (player->planeY * data->cameraX);
	data->deltaDistX = fabs(1 / data->rayDirX);
	data->deltaDistY = fabs(1 / data->rayDirY);
	set_raydir(data, player);
}
