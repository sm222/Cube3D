
#ifndef CUB_H
# define CUB_H

#include "include/structure.h"
#include "include/raycast.h"
#include "lib/lib_ft/libft.h"
#include "lib/minilibx_opengl_20191021/mlx.h"
#include "parsing/parsing.h"
#include "render/render.h"
#include "C_tools/inc/C_tool.h"

void	debug(t_cub cub); //! remove at the end
int		bad_args_main(int ac);
void	set_main_data(t_cub *cub);
void	set_render_data(t_cub *cub);

//image ft
int32_t	return_color_from_image(t_mlx_image *img, int x, int y);
t_err	remove_image(t_mlx_image *src, t_cub *cub);
t_err	import_img(char *file, t_cub *cub, t_mlx_image *dst);
//
int 	import_wall(t_cub *cub);

//
int		keybinds(int keycode, t_cub *cub);

//
int		exit_window(t_cub *cub);
void	mlx_fail_omg(t_cub *cub);
void	free_no_exit(t_cub *cub);
t_err	free_wall(t_cub *cub);

#endif // CUB_H
