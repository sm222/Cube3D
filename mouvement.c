#include "cub.h"

int	keybinds(int keycode, t_cub *cub)
{
	ft_printf(2, "key press = %d\n", keycode);
	if (keycode == 53)
		(void) exit_window(cub);
	return (0);
}