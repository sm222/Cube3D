/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:31:27 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/13 14:31:29 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/// @brief use to see if multiple spawn was find
/// @param c char to look
/// @param s line to print if error found
/// @param i err line
/// @param j len of the error
/// @return return 1 if too menny spawn was found else 0
static short	look_spawn(char c, char *s, size_t i, size_t j)
{
	static char	spawn = 0;

	if (spawn == 0)
	{
		if (ft_strchr("NSEW", c))
			spawn = c;
		return (0);
	}
	if (spawn != 0 && ft_strchr("NSEW", c))
	{
		ft_printf(2, "%oError\n[%u] to menny spawn\n%s\n", NULL, i + 1, s);
		ft_print_err_len(j);
		return (1);
	}
	return (0);
}

/// @brief use to parse the map
/// @param s line of the map
/// @param i y cord of the map
/// @return empty_line, fail or success
static t_err	read_line_map(char *s, size_t const i)
{
	size_t		j;

	j = 0;
	while (s && s[j] && s[j] == ' ')
		j++;
	if (j == ft_strlen(s))
		return (e_empty_line);
	while (s && s[j])
	{
		if (ft_strchr("01 NSEW", s[j]))
		{
			if (look_spawn(s[j], s, i, j))
				return (e_fail);
			j++;
		}
		else
		{
			ft_printf(2, "%oError\n[%u] invalid char\n%s\n", NULL, i + 1, s);
			ft_print_err_len(j++);
			return (e_fail);
		}
	}
	return (e_success);
}

/// @brief use to be useful ? no clue if not broken don't fix it
/// @param map 
/// @return 
static t_map	copy_map_and_valid(t_map map)
{
	t_map	new;

	new = ft_cpy_double_char(map);
	return (new);
}

/// @brief skip all the texture and other information and take the rest
/// @param data main parsing struct
/// @return fail, or success
t_err	extract_map(t_parsing *data)
{
	t_err	err;
	short	flag;
	size_t	i;

	err = 0;
	i = 0;
	flag = 0;
	while (data->pre_map[i + data->i])
	{
		err = read_line_map(data->pre_map[i + data->i], i + data->i);
		if (err < e_success && err != e_empty_line)
			flag = 1;
		i++;
	}
	if (flag)
		return (e_fail);
	data->map = copy_map_and_valid(data->pre_map + data->i);
	if (call_flood_fill(data->map, data) == e_fail)
		return (e_fail);
	return (e_success);
}
