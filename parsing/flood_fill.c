
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
	return (1);
}

int	call_flood_fill(t_map in)
{
	int		err;
	int		x;
	int		y;
	t_map	copy;
	int		up;

	err = 0;
	if (find_spawn(&x, &y, in))
	{
		up = ft_strlen_double(in);
		copy = ft_cpy_double_char(in);
		printf("total %d\n", flood_fill(x, y, copy, &up));
		ft_double_sfree((void **)copy);
	}
	else
		err = e_fail;
	return (err);
}
