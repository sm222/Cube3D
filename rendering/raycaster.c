/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:11 by edufour           #+#    #+#             */
/*   Updated: 2024/02/12 16:42:09 by edufour          ###   ########.fr       */
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

void    draw_vertical_line(t_cub *cub, t_raycasting *data, t_mlx_image *frame, int x)
{
	int y;
	(void)x;

	y = data->drawStart;
	data->step = 1.0 * IMAGE_S / data->lineHeight;
	data->texPos = (data->drawStart - WIN_H / 2 + data->lineHeight / 2) * data->step;
	if (y >= data->drawEnd)
	{
		y = WIN_H / 2 - 10;
		data->drawEnd = WIN_H / 2 + 10;
	}	
	while (y < data->drawEnd)
	{
		data->texY = (int)data->texPos & (IMAGE_S -1);
		//bitwise masking to ensure that data->texY is within the range of 0 to IMAGE_S
		if (data->texY >= IMAGE_S)
			data->texY &= (IMAGE_S - 1);
		data->texPos += data->step;
		data->color = return_color_from_image(&(cub->wall[0]), data->texX, data->texY);
		render_pixel_to_img(data->color, frame, x, y);
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
		//wallX is the exact x-coordinate where the wall was hit, scaled between 0 and 1 to represent a proportion of the wall.
		//Calculated by substacting the integer from the floating point number from the exact position in x and y.
		if (data->side == e_no || data->side == e_so)
			data->wallX = cub->player->playX + data->perpWallDist * data->rayDirX;
		else
			data->wallX = cub->player->playY + data->perpWallDist * data->rayDirY;
		data->wallX -= floor(data->wallX);
		data->texX = (int)(data->wallX * IMAGE_S);
		calculate_wall_height(data);
		//This checks if the texture needs to be reversed (depending on which side was hit)
		// if (((data->side == e_so || data->side == e_no) && data->rayDirX > 0)
			// || ((data->side == e_ea || data->side == e_we) && data->rayDirY < 0))
			// data->texX = IMAGE_S - data->texX - 1;
		draw_vertical_line(cub, data, &cub->ren.frame, x);
		x++;
	}
	return (NULL);
}