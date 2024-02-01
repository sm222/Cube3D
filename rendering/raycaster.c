/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:44:11 by edufour           #+#    #+#             */
/*   Updated: 2024/02/01 17:16:49 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

//0 = x, 1 = y
void    set_north_south(double dir, t_parsing *vectors)
{
    double  p_x;
    double  p_y;

    p_x = vectors->pos_vct_x;
    p_y = vectors->pos_vct_y;
    vectors->dir_vct_x = p_x;
    vectors->dir_vct_y = p_y + (DVCT_LEN * dir);
    vectors->cam_vct_x = p_x + (CP_LEN * dir);
    vectors->cam_vct_y = p_y + (DVCT_LEN * dir);
}

void    set_east_west(double dir, t_parsing *vectors)
{
    vectors->dir_vct_x = p_x + (DVCT_LEN * dir);
    vectors->dir_vct_y = p_y;
    vectors->cam_vct_x = p_x + (DVCT_LEN * dir);
    vectors->cam_vct_y = p_y - (CP_LEN * dir);
}

t_raycasting    *init_vectors(double p_x, double p_y, char dir)
{
    t_raycasting    *vectors;

    vectors = ft_calloc(1, sizeof(t_raycasting));
    if (!vectors)
        return (NULL); //fatal issue here
    p_x += 0.5;
    p_y += 0.5;
    vectors->pos_vct_x = p_x;
    vectors->pos_vct_y = p_y;
    if (dir == N)
        set_north_south(1);
    else if (dir == S)
        set_north_south(-1);
    else if (dir == E)
        set_east_west(1);
    else
        set_east_west(-1);
    return (vectors);
}

//returns a pointer to an image(draws on the image)
void    *raycaster(t_raycasting *pos, void *img_ptr)
{
    
}