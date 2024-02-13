/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:02:36 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/13 09:11:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/// @brief use to clean memorry if somting fail in parsing
/// @param data main struc of parsing
/// @return return success
short	clean_parsing(t_parsing *data)
{
	int	i;

	i = 0;
	data->pre_map = (t_map)ft_double_sfree((void **)data->pre_map);
	while (i < 4)
	{
		data->texture.side[i] = ft_free(data->texture.side[i]);
		i++;
	}
	return (e_success);
}
short	clean_wall_name(t_parsing *data)
{
	short	i;

	i = 0;
	while (i < 4)
	{
		data->texture.side[i] = ft_free(data->texture.side[i]);
		i++;
	}
	return (e_success);
}