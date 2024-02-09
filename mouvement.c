#include "cub.h"

// void	rotate(int dir, t_player *player)
// {
	// player->
// }

void	move(double dirX, double dirY, t_player *player, char **map)
{
	(void)map;
	player->playX += dirX;
	player->playY += dirY;
}

int	keybinds(int keycode, t_cub *cub)
{
	ft_printf(2, "key press = %d\n", keycode);
	if (keycode == 53)
		(void) exit_window(cub);
	if (keycode == 13 || keycode == 126) //w || up arrow
		move(0, -P_SPEED, cub->player, cub->map);
	if (keycode == 2) //d
		move(P_SPEED, 0, cub->player, cub->map);
	if (keycode == 1 || keycode == 125) // s || down arrow
		move(0, P_SPEED, cub->player, cub->map);
	if (keycode == 0) // a
		move(-P_SPEED, 0, cub->player, cub->map);
	// if (keycode == 0) // right arrow
		// rotate();
	// if (keycode == 0) // left arrow
		// rotate();
	return (0);
}