#include "render.h"

int32_t	create_rgb(int r, int g, int b)
{
	int t;

	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

t_err	make_mlx_image(t_mlx_image *ptr, t_cub *cub)
{
	t_render	*render;
	t_mlx_ft	*ft;

	if (!ptr || !cub)
		return (e_bad_args);
	render = &cub->ren;
	ft = &cub->mlx_ft;
	ptr->img = ft->mlx_new_image(cub->mlx, WIN_W, WIN_H);
	ptr->addr = ft->mlx_get_data_addr(ptr->img, &ptr->b_per_pix, \
	&ptr->line_len, &ptr->endian);
	return (e_success);
}

/*
int	set_pixel(int32_t color, int x, int y)
{

}
*/

int	render_pixel_to_img(int32_t color, t_mlx_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->b_per_pix / 8));
	*(unsigned int *)dst = color;
	return (0);
}