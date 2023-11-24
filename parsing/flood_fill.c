
#include "parsing.h"

static short	find_spawn(int *x, int *y, t_map map)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (ft_strchr("NWSE", map[*y][*x]))
				return (1);
			*x += 1;
		}
		*y += 1;
	}
	*y = 0;
	*x = 0;
	return (0);
}

void	flod_err(t_map map, int x, int y)
{
	int				i;
	int				j;
	static short	err = 0;


	if (err > 0)
		return ;
	i = 0;
	ft_printf(2, "%oError\n", NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (y == i && x == j)
				ft_printf(2, "%o"RED"X"WHT, NULL);
			else if (map[i][j] == '\b')
				ft_printf(2, "%o%c", NULL, '0');
			else
				ft_printf(2, "%o%c", NULL, map[i][j]);
			j++;
		}
		ft_printf(2, "%o\n", NULL);
		i++;
	}
	err++;
}

static int	flood_fill(int x, int y, t_map map, int *up)
{
	int	out;

	out = 0;
	if (x < 0 || y < 0 || y > *up || x > (int)ft_strlen(map[y]))
		return (0);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == '0' || ft_strchr("NWES", map[y][x]))
	{
		map[y][x] = '\b';
		out += flood_fill(x + 1, y, map, up);
		out += flood_fill(x - 1, y, map, up);
		out += flood_fill(x, y + 1, map, up);
		out += flood_fill(x, y - 1, map, up);
		return (out);
	}
	if (map[y][x] == '\b')
		return (0);
	flod_err(map, x, y);
	return (1);
}

int	call_flood_fill(t_map in)
{
	int		err;
	int		x;
	int		y;
	t_map	copy;
	int		up;

	err = e_success;
	if (find_spawn(&x, &y, in))
	{
		up = ft_strlen_double(in);
		copy = ft_cpy_double_char(in);
		if (flood_fill(x, y, copy, &up) > 0)
			err = e_fail;
		ft_double_sfree((void **)copy);
	}
	else
		err = e_fail;
	return (err);
}
