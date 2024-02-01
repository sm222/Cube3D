#include "render.h"

int32_t	create_rgb(int r, int g, int b)
{
	int t;

	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

t_err	make_mlx_image(t_mlx_image *ptr, t_cub *cub)
{
	if (!ptr || !cub)
		return (e_bad_args);
	ptr->img = 
}

int	render_pixel_to_img(int32_t color, t_mlx_image *mlx_img, int x, int y)
{
	

}