/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:18:16 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/13 14:27:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/// @brief use to find the longets line in a t_map
/// @param map input
/// @return the len of the longet find line
static int	find_longer_line(t_map const map)
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

/// @brief use in flod_err to print the right char or red X
/// @param line line to print
/// @param err_x x marks the spot
/// @param len of the pad map
/// @param y old safety
static void	print_type(char const *line, int const err_x, \
						int const len, int const y)
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

/// @brief this is call if the flood fill fail in anyway
/// @brief this shoud be only call one time or could look weird on screen
/// @param map use to print the error on screen
/// @param x x error cord
/// @param y y error cord
void	flod_err(t_map const map, int const x, int const y)
{
	int	i;

	i = 0;
	ft_printf(2, "%oError\nCub3D: invalid map\n", NULL);
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

/// @brief use to floodfill the map to find holes and see if it valid
/// @param x were to look in the map
/// @param y were to look in the map
/// @param map use to floodfill
/// @param last last side on witch one was call
/// @return 0 if sucsess, 1 if error
static int	flood_fill(int x, int y, t_map const map, char last)
{
	int	out;

	out = 0;
	if ((x < 0 || y < 0))
		return (1);
	if (map[y][x] == '1' || map[y][x] == '\b' || ft_strchr("nwes", map[y][x]))
		return (0);
	if (map[y][x] == '0' || ft_strchr("NWES", map[y][x]))
	{
		if (map[y][x] == '0')
			map[y][x] = '\b';
		else
			map[y][x] = map[y][x] + 32;
		if (last != 'u')
			out += flood_fill(x, y - 1, map, 'd');
		if (last != 'd')
			out += flood_fill(x, y + 1, map, 'u');
		if (last != 'l')
			out += flood_fill(x - 1, y, map, 'r');
		if (last != 'r')
			out += flood_fill(x + 1, y, map, 'l');
		return (out);
	}
	flod_err(map, x, y);
	return (1);
}

/// @brief use to make the (safe) map and look if it is valid
/// @param in in map use make the new one
/// @param data main data structure of parsing
/// @return fail if problem or successe
int	call_flood_fill(t_map in, t_parsing *data)
{
	int		x;
	int		y;
	t_map	safe;

	safe = make_safe_copy(in, find_longer_line(in));
	if (find_spawn(&x, &y, safe) == e_success)
	{
		data->texture.p_x = x;
		data->texture.p_y = y;
		if (flood_fill(x, y, safe, 'm') > 0)
		{
			safe = (t_map)ft_double_sfree((void **)safe);
			data->map = (t_map)ft_double_sfree((void **)data->map);
			return (e_fail);
		}
		safe = (t_map)ft_double_sfree((void **)safe);
		data->map = make_safe_copy(in, find_longer_line(in));
		ft_double_sfree((void **)in);
		return (e_success);
	}
	safe = (t_map)ft_double_sfree((void **)safe);
	data->map = (t_map)ft_double_sfree((void **)data->map);
	ft_printf(2, "%oError\nCub3D: no spawn given\n", NULL);
	return (e_fail);
}
