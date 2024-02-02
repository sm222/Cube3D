
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

#endif // CUB_H
