
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

static	int find_longer_line(t_map map)
{
	int	len;
	int	tmp;
	int	i;

	i = 0;
	len = 0;
	while (map && map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > len)
			len = tmp;
		i++;
	}
	return (len);
}

static char rt_char(char c)
{
	if (c == '\b')
		return ('0');
	return (c);
}

static void	print_type(char *line , int err_x, int len, int y)
{
	int	i;
	int	len_line;

	i = 0;
	len_line = ft_strlen(line);
	while (i < len)
	{
		if (i < len_line && i != err_x)
			ft_printf(2, "%o%c", NULL, rt_char(line[i]));
		else if (i < len_line && !y)
			ft_printf(2, "%o%c", NULL, rt_char(line[i]));
		else if (i == err_x && y)
			ft_printf(2, "%o"RED"X"WHT, NULL);
		else
			ft_printf(2, "%o ", NULL);
		i++;
	}
}


void	flod_err(t_map map, int x, int y)
{
	int				i;
	static short	err = 0;


	(void)y;
	if (err > 0)
		return ;
	i = 0;
	err = ft_printf(2, "%oError \n", NULL);
	while (map[i])
	{
		if (i == y)
			print_type(map[i], x, find_longer_line(map), 1);
		else
			print_type(map[i], x, find_longer_line(map), 0);
		i++;
		ft_printf(2, "%o\n", NULL);
	}
}

int	flood_fill(int x, int y, t_map map, int *up)
{
	int	out;

	out = 0;
	if (x < 0 || y < 0 || y > *up || x > (int)ft_strlen(map[y]))
	{
		if (y > *up && ft_strlen(map[y]) > ft_strlen(map[y - 1]))
			return (0);
	}
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
	//t_map	copy;
	//int		up;

	err = e_success;
	make_safe_copy(in, find_longer_line(in));
	if (find_spawn(&x, &y, in))
	{
		//up = ft_strlen_double(in);
		//copy = ft_cpy_double_char(in);
		//if (flood_fill(x, y, copy, &up) > 0)
		//	err = e_fail;
		//ft_double_sfree((void **)copy);
	}
	else
		err = e_fail;
	return (err);
}
