/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:57:22 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/24 18:00:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set_str(char *s, t_str *data)
{
	if (!data)
		return (-1);
	data->s = s;
	data->len = ft_strlen(data->s);
	data->i = 0;
	data->j = 0;
	return (1);
}