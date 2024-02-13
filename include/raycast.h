/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:47:56 by edufour           #+#    #+#             */
/*   Updated: 2024/02/13 15:22:47 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../include/structure.h"
# include <math.h>

//DVCT stands for direction vector
//CP stands for camera plane
# define P_SPEED 0.4
# define FOV 90
# define ROTSPEED 0.2

void            *raycaster(t_cub *cub, t_raycasting *data);
int32_t         return_color_from_image(t_mlx_image *img, int x, int y);
void	        set_raydir(t_raycasting *data, t_player *player);
void        	init_raydata(int x, t_raycasting *data, t_player *player);

#endif
