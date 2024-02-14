/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:16:26 by edufour           #+#    #+#             */
/*   Updated: 2024/02/14 12:48:17 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycast.h"

//work
int32_t	return_color_from_image(t_mlx_image *img, int x, int y)
{
	char	*dst;

	if (!img || x < 0 || y < 0 || x > IMAGE_S || y > IMAGE_S)
		return (0);
	dst = img->addr + (y * img->line_len + x * (img->b_per_pix / 8));
	return (*(unsigned int *)dst);
}

//
t_err	remove_image(t_mlx_image *src, t_cub *cub)
{
	t_mlx_ft	*ft;

	ft = &cub->mlx_ft;
	if (!src)
		return (e_bad_args);
	if (src->img)
	{
		ft->mlx_destroy_image(cub->mlx, src->img);
		src->img = NULL;
		return (e_success);
	}
	return (e_fail);
}

//work
t_err	import_img(char *file, t_cub *cub, t_mlx_image *dst)
{
	t_mlx_ft	*ft;
	int			w;
	int			h;

	if (!file || !cub || !dst)
		return (e_bad_args);
	ft = &cub->mlx_ft;
	dst->img = ft->mlx_xpm_file_to_image(cub->mlx, file, &w, &h);
	if (!dst->img)
		return (e_malloc_f);
	if (w != IMAGE_S || h != IMAGE_S)
		return ((void)remove_image(dst, cub), e_bad_size);
	dst->addr = ft->mlx_get_data_addr(dst->img, &dst->b_per_pix, \
	&dst->line_len, &dst->endian);
	return (e_success);
}
