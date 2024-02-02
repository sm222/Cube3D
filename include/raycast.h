/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:47:56 by edufour           #+#    #+#             */
/*   Updated: 2024/02/02 13:01:38 by edufour          ###   ########.fr       */
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

typedef struct s_raycasting
{
    double  pos_vct_x;
    double  pos_vct_y;
    double  dir_vct_x;
    double  dir_vct_y;
    double  cam_vct_x;
    double  cam_vct_y;
}	t_raycasting;

void    *raycaster(t_cub *cub);

#endif
