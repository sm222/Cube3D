/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:14:35 by edufour           #+#    #+#             */
/*   Updated: 2024/02/15 13:20:42 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate(int dir, t_player *player)
{
	double	olddirx;
	double	oldplanex;

	olddirx = player->dirx;
	player->dirx = player->dirx * cos(ROTSPEED * dir) \
		- player->diry * sin(ROTSPEED * dir);
	player->diry = olddirx * sin(ROTSPEED * dir) \
		+ player->diry * cos(ROTSPEED * dir);
	oldplanex = player->planex;
	player->planex = player->planex * cos(ROTSPEED * dir) \
		- player->planey * sin(ROTSPEED * dir);
	player->planey = oldplanex * sin(ROTSPEED * dir) \
		+ player->planey * cos(ROTSPEED * dir);
}

void	move_forward_backward(int dir, t_player *player, char **map)
{
	int	x;
	int	y;

	x = (int)(player->playx + (player->dirx * dir) * P_SPEED);
	y = (int)player->playy;
	if (map[y][x] != '1')
	{
		player->playx += (player->dirx * dir) * P_SPEED;
	}
	x = (int)player->playx;
	y = (int)(player->playy + (player->diry * dir) * P_SPEED);
	if (map[y][x] != '1')
	{
		player->playy += (player->diry * dir) * P_SPEED;
	}
}

void	move_sideways(double dir, t_player *p, char **map)
{
	if (dir == 'a')
	{
		if (map[(int)p->playy][(int)(p->playx + p->diry * P_SPEED)] != '1')
		{
			p->playx += p->diry * P_SPEED;
		}
		if (map[(int)(p->playy - p->dirx * P_SPEED)][(int)p->playx] != '1')
		{
			p->playy -= p->dirx * P_SPEED;
		}
	}
	if (dir == 'd')
	{
		if (map[(int)p->playy][(int)(p->playx - p->diry * P_SPEED)] != '1')
		{
			p->playx -= p->diry * P_SPEED;
		}
		if (map[(int)(p->playy + p->dirx * P_SPEED)][(int)p->playx] != '1')
		{
			p->playy += p->dirx * P_SPEED;
		}
	}
}

int	keybinds(int keycode, t_cub *cub)
{
	if (keycode == 53)
		(void) exit_window(cub);
	if (keycode == 13 || keycode == 126)
		move_forward_backward(1, cub->player, cub->map);
	if (keycode == 2)
		move_sideways('d', cub->player, cub->map);
	if (keycode == 1 || keycode == 125)
		move_forward_backward(-1, cub->player, cub->map);
	if (keycode == 0)
		move_sideways('a', cub->player, cub->map);
	if (keycode == 123)
		rotate(-1, cub->player);
	if (keycode == 124)
		rotate(1, cub->player);
	return (0);
}
