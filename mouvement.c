#include "cub.h"

void	rotate(int dir, t_player *player)
{
    double olddirx;
    double oldplanex;
	
	olddirx = player->dirx;
    player->dirx = player->dirx * cos(ROTSPEED * dir) - player->diry * sin(ROTSPEED * dir);
    player->diry = olddirx * sin(ROTSPEED * dir) + player->diry * cos(ROTSPEED * dir);
	oldplanex = player->planex;
    player->planex = player->planex * cos(ROTSPEED * dir) - player->planey * sin(ROTSPEED * dir);
    player->planey = oldplanex * sin(ROTSPEED * dir) + player->planey * cos(ROTSPEED * dir);
}

void	move(double dir, t_player *player, char **map)
{

	int	dirx;
	int	diry;

	dirx = (player->diry) * -1;
    diry = player->dirx;
	if (dir == 'w')
	{
		if(map[(int)player->playy][(int)(player->playx + player->dirx * P_SPEED)] != '1') 
			player->playx += player->dirx * P_SPEED;
    	if(map[(int)(player->playy + player->diry * P_SPEED)][(int)player->playx] != '1')
			player->playy += player->diry * P_SPEED;
	}
	if (dir == 's')
	{
		if(map[(int)player->playy][(int)(player->playx - player->dirx * P_SPEED)] != '1') 
			player->playx -= player->dirx * P_SPEED;
    	if(map[(int)(player->playy - player->diry * P_SPEED)][(int)player->playx] != '1')
			player->playy -= player->diry * P_SPEED;
	}
	if (dir == 'a')
	{
		if(map[(int)player->playy][(int)(player->playx + player->diry * P_SPEED)] != '1') 
			player->playx += player->diry * P_SPEED;
    	if(map[(int)(player->playy - player->dirx * P_SPEED)][(int)player->playx] != '1')
			player->playy -= player->dirx * P_SPEED;
	}
	if (dir == 'd')
	{
		if(map[(int)player->playy][(int)(player->playx - player->diry * P_SPEED)] != '1') 
			player->playx -= player->diry * P_SPEED;
    	if(map[(int)(player->playy + player->dirx * P_SPEED)][(int)player->playx] != '1')
			player->playy += player->dirx * P_SPEED;
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