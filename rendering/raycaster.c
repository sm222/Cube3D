/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:11 by edufour           #+#    #+#             */
/*   Updated: 2024/02/02 18:16:07 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"

//0 = x, 1 = y
void    set_north_south(double dir, t_raycasting *vectors)
{
    double  p_x;
    double  p_y;

    p_x = vectors->posX;
    p_y = vectors->posY;
    vectors->dirVctX = p_x;
    vectors->dirVctY = p_y + (DVCT_LEN * dir);
    vectors->cam_vct_x = p_x - (CP_LEN * dir);
    vectors->cam_vct_y = p_y + (DVCT_LEN * dir);
}

void    set_east_west(double dir, t_raycasting *vectors)
{
    double  p_x;
    double  p_y;

    p_x = vectors->posX;
    p_y = vectors->posY;
    vectors->dirVctX = p_x + (DVCT_LEN * dir);
    vectors->dirVctY = p_y;
    vectors->cam_vct_x = p_x + (DVCT_LEN * dir);
    vectors->cam_vct_y = p_y + (CP_LEN * dir);
}

//This inits the player's position in X and Y, as well as the direction vector
//and the camera plane's absolute right position.
void    init_vectors(t_raycasting *data, double p_x, double p_y, char dir)
{
    p_x += 0.5;
    p_y += 0.5;
    data->posX = p_x;
    data->posY = p_y;
    if (dir == 'N')
        set_north_south(-1, data);
	else if (dir == 'S')
    	set_north_south(1, data);
    else if (dir == 'E')
    	set_east_west(1, data);
    else
        set_east_west(-1, data);
}

void    init_rayData(int x, t_raycasting *data)
{
    data->mapX = (int)data->posX;
    data->mapX = (int)data->posY;
    //This next section aims at scaling cameraX to represent the 
    //x-coordinate on the camera plane coresponding to the column of the screen which will be printed next.
    //It then calculates the direction of the ray by placing a point on the camera plane (rayDir)
    //through which the ray will be casted from the player's position.
    data->cameraX = 2 * x / (double)WIN_W -1;
    data->rayDirX = data->posX + data->cam_vct_x * data->cameraX;
    data->rayDirY = data->posY + data->cam_vct_y * data->cameraX;
    //Here, the delta distances are calculated for later use in the DDA algorithm.
    //deltaDistX represents the ratio of the change in the x-coordinate
    //of the ray's position to the change in distance traveled along the x-axis.
    //So, multiplying this ratio by a certain distance gives you the corresponding change in the ray's x-coordinate.
    data->deltaDistX = fabs(1 / data->rayDirX);
    data->deltaDistY = fabs(1 / data->rayDirY);
    if (data->rayDirX < 0)
    {
        data->stepX = -1;
        data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
    }
    else
    {
        data->stepX = 1;
        data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
    }
    if (data->rayDirY < 0)
    {
        data->stepY = -1;
        data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
    }
    else
    {
        data->stepY = 1;
        data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
    }
}

void    jump_dirX(t_raycasting *data)
{
    data->sideDistX += data->deltaDistX;
    data->mapX += data->stepX;
    if (data->stepX > 0)
        data->side = 3;
    else
        data->side = 2;
}

void    jump_dirY(t_raycasting *data)
{
    data->sideDistY += data->deltaDistY;
    data->mapY += data->stepY;
    if(data->stepY > 0)
        data->side = 1;
    else
        data->side = 0;
}

// returns a pointer to an image(draws on the image) (either draws directly on
// and returns the pointer given as argument or creates a copy and returns it)
void    *raycaster(t_cub *cub)
{
    t_raycasting    data;
    int             x;

    x = 0;
    init_vectors(&data, cub->pars.texture.p_x, cub->pars.texture.p_x, cub->pars.texture.p_looking);
    while (x < WIN_W)
    {
        init_rayData(x, &data);
        while (data.hit == 0)
        {
            if (data.sideDistX < data.sideDistY)
                jump_dirX(&data);
            else
                jump_dirY(&data);
            if (cub->map[data.mapX][data.mapY] > 0)
                data.hit = 1;
        }
        //1 : calculate distance from camera plane
        //2 : retrieve position on texture
        //3 : draw column on image
        x++;
    }
    return (NULL); //img_ptr
}