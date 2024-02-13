/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:18:01 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/13 09:18:11 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/// @brief use to find the starting poin of the flodfill
/// @param x use a &int input to return the value
/// @param y use a &int input to return the value
/// @param map t_map as a input
/// @return return e_success if found or fail and set back x and y to 0
short	find_spawn(int *x, int *y, const t_map map)
{
	if (!map)
	{
		ft_printf(2, "Error\nCub3D: malloc fail\n");
		return (e_malloc_f);
	}
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (ft_strchr("NWSE", map[*y][*x]))
				return (e_success);
			*x += 1;
		}
		*y += 1;
	}
	*y = 0;
	*x = 0;
	return (e_fail);
}

/// @brief use to add pading the the map, add a line of space above and under
/// @param map the one and only 
/// @param len len of the box (char *) firt star
/// @param max_len the longest line of map
/// @return success, or malloc_fail
static short	set_space(t_map map, size_t const len, size_t const max_len)
{
	map[0] = ft_calloc(max_len + 2, sizeof(char));
	if (!map[0])
		return (e_malloc_f);
	map[len - 2] = ft_calloc(max_len + 2, sizeof(char));
	if (!map[len - 2])
	{
		ft_free(map[0]);
		return (e_malloc_f);
	}
	ft_memset(map[0], ' ', max_len - 1);
	ft_memset(map[len - 2], ' ', max_len - 1);
	return (e_success);
}

/// @brief use to buff the line on the map with one space at the start
/// @brief and to get to max at the end
/// @param old use as a guide for the new map
/// @param new map that will add the new line, need to be malloc
/// @param max max len of the line can get
/// @return return malloc_fail or success
static short	add_space_to_line(t_map const old, t_map new, size_t const max)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	while (old && old[i])
	{
		len = max - ft_strlen(old[i] + 1);
		tmp = ft_calloc(len + 1, sizeof(char));
		if (!tmp)
			return (e_malloc_f);
		ft_memset(tmp, ' ', len);
		ft_printf(NO_PRINT, "%o %s%s", &new[i + 1], old[i], tmp);
		tmp = ft_free(tmp);
		if (!new[i + 1])
			return (e_malloc_f);
		i++;
	}
	return (e_success);
}

/// @brief use to make a (safe) copy of map. by safe it pad with space
/// @param map the one use for copy
/// @param max_len longet line of the map
/// @return NULL if fail or the new (safe) map
t_map	make_safe_copy(t_map const map, size_t const max_len)
{
	size_t	len;
	t_map	new_map;

	len = ft_strlen_double(map) + 3;
	new_map = ft_calloc(len + 1, sizeof(char *));
	if (set_space(new_map, len, max_len + 3) < e_success)
	{
		ft_printf(2, "%oError\nCub3D: malloc fail\n", NULL);
		ft_free(new_map);
		return (NULL);
	}
	if (add_space_to_line(map, new_map, max_len) < e_success)
	{
		new_map[len - 2] = ft_free(new_map[len - 2]);
		new_map = (char **)ft_double_sfree((void **)new_map);
		ft_printf(2, "%oError\nCub3D: malloc fail\n", NULL);
	}
	return (new_map);
}

/// @brief use to print the righ char in the error message
/// @param c input
/// @return char to print
char	rt_char(char c)
{
	if (c == '\b')
		return ('0');
	if (c == 's' || c == 'n' || c == 'w' || c == 'e')
		return (c - 32);
	return (c);
}
