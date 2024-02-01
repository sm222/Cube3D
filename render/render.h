
#ifndef RENDER_H
# define RENDER_H

//--------------------------//
//			include			//
//--------------------------//

# include "../lib/lib_ft/libft.h"
# include "../lib/minilibx_opengl_20191021/mlx.h"
# include "../include/structure.h"

//--------------------------//
//			define			//
//--------------------------//

# ifndef WIN_SIZE
#  define WIN_SIZE
#  define WIN_H 1000
#  define WIN_W 1000
# endif

//--------------------------//
//			enum			//
//--------------------------//

enum e_r_mode {
	e_clean,
	e_add_l,
	e_render,
};

//--------------------------//
//			ft				//
//--------------------------//

int	render(t_cub *data, short mode, int **layer);

int32_t	create_rgb(int r, int g, int b);

#endif // RENDER_H
