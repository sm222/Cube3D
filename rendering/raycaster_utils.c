/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:19:05 by edufour           #+#    #+#             */
/*   Updated: 2024/02/13 15:58:38 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/raycast.h"

void	set_north_south(double dir, t_player *vectors)
{
	vectors->dirx = 0;
	vectors->diry = dir;
	vectors->planex = vectors->diry * (-(double)FOV / 100);
	vectors->planey = vectors->dirx * ((double)FOV / 100);
}

void	set_east_west(double dir, t_player *vectors)
{
	vectors->dirx = dir;
	vectors->diry = 0;
	vectors->planex = vectors->diry * (-(double)FOV / 100);
	vectors->planey = vectors->dirx * ((double)FOV / 100);
}

void	set_raydir(t_raycasting *data, t_player *player)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (player->playx - data->mapx) * data->deltadistx;
	}
	else
	{
		data->stepx = 1;
		data->sidedistx = (data->mapx + 1.0 - player->playx) * data->deltadistx;
	}
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (player->playy - data->mapy) * data->deltadisty;
	}
	else
	{
		data->stepy = 1;
		data->sidedisty = (data->mapy + 1.0 - player->playy) * data->deltadisty;
	}
}

void	init_raydata(int x, t_raycasting *data, t_player *player)
{
	data->mapx = player->playx;
	data->mapy = player->playy;
	data->camerax = ((2 * x) / (double)WIN_W) - 1;
	data->raydirx = player->dirx + (player->planex * data->camerax);
	data->raydiry = player->diry + (player->planey * data->camerax);
	data->deltadistx = fabs(1 / data->raydirx);
	data->deltadisty = fabs(1 / data->raydiry);
	set_raydir(data, player);
}
