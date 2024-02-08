/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:47:56 by edufour           #+#    #+#             */
/*   Updated: 2024/02/08 14:30:02 by anboisve         ###   ########.fr       */
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

void	*raycaster(t_cub *cub);

#endif
