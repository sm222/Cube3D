/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:47:56 by edufour           #+#    #+#             */
/*   Updated: 2024/02/02 17:42:09 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../include/structure.h"
# include <math.h>

//DVCT stands for direction vector
//CP stands for camera plane
//WIN_RES is the 
# define P_SPEED 0.5
# define DVCT_LEN 1
# define CP_LEN 1
# define WIN_RES 8

//rayDirX/Y are the points on the camera plane needed to determine the ray's direction
//(Ray is casted from the player's position and goes throught this point in the camera plane)
typedef struct s_raycasting
{
    double  posX;
    double  posY;
    double  dirVctX;
    double  dirVctY;
    double  cam_vct_x;
    double  cam_vct_y;
    double  cameraX;
    double  rayDirX;
    double  rayDirY;
    int     mapX;
    int     mapY;
    double  sideDistX;
    double  sideDistY;
    double  deltaDistX;
    double  deltaDistY;
    double  perpWallDist;
    int     stepX;
    int     stepY;
    int     hit;
    int     side;
}	t_raycasting;

void    *raycaster(t_cub *cub);

#endif
