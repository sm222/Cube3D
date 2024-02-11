/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:11 by edufour           #+#    #+#             */
/*   Updated: 2024/02/11 13:08:37 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"
#include "../render/render.h"

void    set_north_south(double dir, t_player *vectors)
{
	vectors->dirX = 0;
	vectors->dirY = dir;
	vectors->planeX = vectors->dirY * (-(double)FOV / 100);
	vectors->planeY = vectors->dirX * ((double)FOV / 100);
}

void    set_east_west(double dir, t_player *vectors)
{
	vectors->dirX = dir;
	vectors->dirY = 0;
	vectors->planeX = vectors->dirY * (-(double)FOV / 100);
	vectors->planeY = vectors->dirX * ((double)FOV / 100);
}

void    init_rayData(int x, t_raycasting *data, t_player *player)
{
	data->mapX = player->playX;
	data->mapY = player->playY;
	//This next section aims at scaling cameraX to represent the 
	//x-coordinate on the camera plane coresponding to the column of the screen which will be printed next.
	//It then calculates the direction of the ray by placing a point on the camera plane (rayDir)
	//through which the ray will be casted from the player's position.
	data->cameraX = ((2 * x) / (double)WIN_W) - 1;
	data->rayDirX = player->dirX + (player->planeX * data->cameraX);
	data->rayDirY = player->dirY + (player->planeY * data->cameraX);
	//Here, the delta distances are calculated for later use in the DDA algorithm.
	//deltaDistX represents the ratio of the change in the x-coordinate
	//of the ray's position to the change in distance traveled along the x-axis.
	//So, multiplying this ratio by a certain distance gives you the corresponding change in the ray's x-coordinate.
	data->deltaDistX = fabs(1 / data->rayDirX);
	data->deltaDistY = fabs(1 / data->rayDirY);
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

void    jump_dirX(t_raycasting *data)
{
	data->sideDistX += data->deltaDistX;
	data->mapX += data->stepX;
	if (data->stepX > 0)
		data->side = e_we;
	else
		data->side = e_ea;
}

void    jump_dirY(t_raycasting *data)
{
	data->sideDistY += data->deltaDistY;
	data->mapY += data->stepY;
	if(data->stepY > 0)
		data->side = e_so;
	else
		data->side = e_no;
}

void    calculate_wall_height(t_raycasting *data)
{
	if(data->side == e_ea || data->side == e_we)
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

void    draw_vertical_line(t_raycasting *data, int32_t color, t_mlx_image *frame, int x)
{
	int y;

	y = data->drawStart;
	if (y >= data->drawEnd)
	{
		printf("too smoll\n");
		y = WIN_H / 2 - 10;
		data->drawEnd = WIN_H / 2 + 10;
	}	
	while (y <= data->drawEnd)
	{
		render_pixel_to_img(color, frame, x, y);
		y++;
	}
}

void	print_info(t_raycasting *data, double x)
{
	printf("height : %f\n", data->lineHeight);
	printf("cameraX : %f\n", data->cameraX);
	printf("x : %f\n", x);
}

// returns a pointer to an image(draws on the image) (either draws directly on
// and returns the pointer given as argument or creates a copy and returns it)
void    *raycaster(t_cub *cub, t_raycasting *data)
{
	int             x;

	x = 0;
	while (x < WIN_W)
	{
		init_rayData(x, data, cub->player);
		while (data->hit == 0)
		{
			// printf("mapx : %d, mapy : %d, ray : %d", data->);
			if (data->sideDistX < data->sideDistY)
				jump_dirX(data);
			else
				jump_dirY(data);
			if (cub->map[data->mapY][data->mapX] == '1')
				data->hit = 1;
		}
		data->hit = 0;
		calculate_wall_height(data);
		if (data->side == e_no)
			data->color = create_rgb(204, 0, 204); //purple
		else if (data->side == e_so)
			data->color = create_rgb(168, 50, 58); //red
		else if (data->side == e_ea)
			data->color = create_rgb(64, 50, 168); // blue
		else
			data->color = create_rgb(50, 168, 82); // green
		draw_vertical_line(data, data->color, &cub->ren.frame, x);
		x++;
	}
	return (NULL);
}