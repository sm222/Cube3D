#include "render.h"

static void	set_back_ground(t_render *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->img_i == image2)
	{
		while (y < WIN_W)
		{
			/* code */
		}
		
	}
	else
	{
		
	}
}

static void	clean_image(t_render *data)
{
	if (data->img_i == image2)
	{
		ft_bzero(data->image2, (WIN_H) * sizeof(int));
	}
	else
	{
		ft_bzero(data->image1, (WIN_H) * sizeof(int));
	}
}

int	render(t_cub *data, short mode)
{
	if (mode == clean)
	{
		clean_image(&data->ren);

	}

	return (0);
}