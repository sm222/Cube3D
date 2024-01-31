#include "rander.h"

int	test(t_cub *data)
{
	int x;
	static int blue = 0;
	static int y = 0;

	x = 0;
	while (x < WIN_W)
	{
		
		x++;
	}
	y++;
	if (y > WIN_H)
	{
		blue += 50;
		y = 0;
	}
	return (0);
}