#include "cub.h"

void	rotate(int dir, t_player *player)
{
    double oldDirX;
    double oldPlaneX;
	
	oldDirX = player->dirX;
    player->dirX = player->dirX * cos(rotSpeed * dir) - player->dirY * sin(rotSpeed * dir);
    player->dirY = oldDirX * sin(rotSpeed * dir) + player->dirY * cos(rotSpeed * dir);
	oldPlaneX = player->planeX;
    player->planeX = player->planeX * cos(rotSpeed * dir) - player->planeY * sin(rotSpeed * dir);
    player->planeY = oldPlaneX * sin(rotSpeed * dir) + player->planeY * cos(rotSpeed * dir);
}

void	move(double dirX, double dirY, t_player *player, char **map)
{
	(void)map;
	if (dirX != 0)
		player->playX += (player->dirX * P_SPEED) * dirX;
	if (dirY != 0)
	player->playY += (player->dirY * P_SPEED) * dirY;
}

int	keybinds(int keycode, t_cub *cub)
{
	ft_printf(2, "key press = %d\n", keycode);
	if (keycode == 53)
		(void) exit_window(cub);
	if (keycode == 13 || keycode == 126) //w || up arrow
		move(0, -1, cub->player, cub->map);
	if (keycode == 2) //d
		move(1, 0, cub->player, cub->map);
	if (keycode == 1 || keycode == 125) // s || down arrow
		move(0, 1, cub->player, cub->map);
	if (keycode == 0) // a
		move(-1, 0, cub->player, cub->map);
	if (keycode == 123) // right arrow
		rotate(-1, cub->player);
	if (keycode == 124) // left arrow
		rotate(1, cub->player);
	return (0);
}