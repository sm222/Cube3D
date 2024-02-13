/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:28:51 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/13 15:40:19 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_err	test_file_name(t_parsing *parsing)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(parsing->texture.side[i], O_RDONLY);
		close(fd);
		if (fd < 0)
		{
			ft_printf(2, "%oError:\n%s is not a valid file.\n", NULL, \
			parsing->texture.side[i]);
			return (e_fail);
		}
		i++;
	}
	return (e_success);
}

/// @brief use to set a err len for the print of the red line
/// @param in add set or get this value
/// @param set_get flag e_cube
/// @return len of i
size_t	read_and_set_err_p(size_t in, short set_get)
{
	size_t	*i;

	i = ft_return_ptr(NULL, e_p_err_index);
	if (set_get == e_set)
		*i = in;
	if (set_get == e_add)
		(*i) += in;
	return (*i);
}

/// @brief make all the verification one by one
/// @param data main struct parsing
/// @return error form fontion call of fail or success
static t_err	look_all(t_parsing *data)
{
	t_err	rvalue;

	rvalue = 0;
	rvalue += parsing_err(data, read_map(data));
	if (rvalue < e_success)
		return (clean_parsing(data), rvalue);
	rvalue += parsing_err(data, parsing_look_c(data));
	if (rvalue < e_success)
		return (clean_parsing(data), rvalue);
	rvalue = extract_texture(data);
	if (rvalue < e_success)
		return (clean_parsing(data), rvalue);
	if (extract_map(data) < e_success || test_file_name(data) < e_success)
	{
		clean_parsing(data);
		return (e_fail);
	}
	data->texture.p_looking = data->map[data->texture.p_y][data->texture.p_x];
	data->pre_map = (t_map)ft_double_sfree((void **)data->pre_map);
	return (e_success);
}

/// @brief use to make and parse a map
/// @param arg name of the file
/// @param cub the main struc
/// @return map if sucsess or NULL if error
t_map	parsing(char *arg, t_cub *cub)
{
	t_parsing	data;

	ft_bzero(&data, sizeof(t_parsing));
	ft_return_ptr(&data, e_parsing);
	ft_return_ptr(&data.err_p, e_p_err_index);
	if (!arg)
		return (NULL);
	data.map_name = arg;
	if (open_file(&data, arg) == -1)
		return (NULL);
	if (look_all(&data) < e_success)
		return (NULL);
	ft_memcpy(&cub->pars, &data, sizeof(t_parsing));
	cub->map = data.map;
	return (data.map);
}
