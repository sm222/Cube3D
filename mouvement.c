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

void	move(double dir, t_player *player, char **map)
{

	int	dirX;
	int	dirY;

	dirX = (player->dirY) * -1;
    dirY = player->dirX;
	if (dir == 'w')
	{
		if(map[(int)player->playY][(int)(player->playX + player->dirX * P_SPEED)] != '1') 
			player->playX += player->dirX * P_SPEED;
    	if(map[(int)(player->playY + player->dirY * P_SPEED)][(int)player->playX] != '1')
			player->playY += player->dirY * P_SPEED;
	}
	if (dir == 's')
	{
		if(map[(int)player->playY][(int)(player->playX - player->dirX * P_SPEED)] != '1') 
			player->playX -= player->dirX * P_SPEED;
    	if(map[(int)(player->playY - player->dirY * P_SPEED)][(int)player->playX] != '1')
			player->playY -= player->dirY * P_SPEED;
	}
	if (dir == 'a')
	{
		if(map[(int)player->playY][(int)(player->playX + player->dirY * P_SPEED)] != '1') 
			player->playX += player->dirY * P_SPEED;
    	if(map[(int)(player->playY - player->dirX * P_SPEED)][(int)player->playX] != '1')
			player->playY -= player->dirX * P_SPEED;
	}
	if (dir == 'd')
	{
		if(map[(int)player->playY][(int)(player->playX - player->dirY * P_SPEED)] != '1') 
			player->playX -= player->dirY * P_SPEED;
    	if(map[(int)(player->playY + player->dirX * P_SPEED)][(int)player->playX] != '1')
			player->playY += player->dirX * P_SPEED;
	}
}

int	keybinds(int keycode, t_cub *cub)
{
	ft_printf(2, "key press = %d\n", keycode);
	if (keycode == 53)
		(void) exit_window(cub);
	if (keycode == 13 || keycode == 126) //w || up arrow
		move('w', cub->player, cub->map);
	if (keycode == 2) //d
		move('d', cub->player, cub->map);
	if (keycode == 1 || keycode == 125) // s || down arrow
		move('s', cub->player, cub->map);
	if (keycode == 0) // a
		move('a', cub->player, cub->map);
	if (keycode == 123) // right arrow
		rotate(-1, cub->player);
	if (keycode == 124) // left arrow
		rotate(1, cub->player);
	return (0);
}