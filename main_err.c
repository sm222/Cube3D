#include "cub.h"

int	bad_args_main(int ac)
{
	ft_printf(2, "%oError\n", NULL);
	if (ac > 2)
		ft_printf(2, "%oCub3D: too many argument\n", NULL);
	else
		ft_printf(2, "%oCub3D: need one argument, *.cub\n", NULL);
	return (1);
}