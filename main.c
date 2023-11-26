#include "include/structure.h"
#include "lib/lib_ft/libft.h"
#include "lib/minilibx_opengl_20191021/mlx.h"
#include "parsing/parsing.h"
#include "C_tools/inc/C_tool.h"


int	exit_window(t_cub *info)
{
	(void)info;
	//mlx_destroy_window(info->mlx, info->window);
	exit(0); //you need it ;)
	return (0);
}

int	keybinds(int keycode, t_cub *info)
{
	if (keycode == 53)
		exit_window(info);
	return (0);
}

/*
	use to set all the usefull data and the start of the program
	*	ft_return_ptr is use like a set and get from any place
	*	or the data need to come from the main or is malloc so
	*	the value is not lost
*/
static void	set_main_data(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	ft_return_ptr(cub, e_data);
}

static int	bad_args_main(int ac)
{
	ft_printf(2, "%oError\n", NULL);
	if (ac > 2)
		ft_printf(2, "%otoo many argument\n", NULL);
	else
		ft_printf(2, "%oneed one argument, *.cub\n", NULL);
	return (1);
}

/*
/The "param" argument in mlx functions represents the argument 
taken by the preceding function argument./
*/
int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac < 2 || ac > 2)
		return (bad_args_main(ac));
	set_main_data(&cub);
	if (!parsing(av[1]))
		return (1);
	//cub.mlx = mlx_init();
	//cub.window = mlx_new_window(cub.mlx, 10 * 64, 10 * 64, "test");
	//mlx_key_hook(cub.window, keybinds, &cub);
	//mlx_hook(cub.window, 17, 0, exit_window, &cub);
	//mlx_loop(cub.mlx);
}
