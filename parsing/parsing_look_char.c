/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_look_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:31:14 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/13 14:31:15 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/// @brief look for invalid char
/// @param data main struc parsing
/// @return success or bad_char
t_err	parsing_look_c(t_parsing *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->pre_map && data->pre_map[i])
	{
		j = 0;
		while (data->pre_map[i][j])
		{
			if (ft_strchr("	'\"", \
			data->pre_map[i][j]) != NULL)
			{
				data->err = data->pre_map[i][j];
				data->errh = i + 1;
				data->errw = j + 1;
				data->err_line = data->pre_map[i];
				return (e_bad_char);
			}
			j++;
		}
		i++;
	}
	return (e_success);
}
