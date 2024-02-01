/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:57:22 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/26 11:24:12 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_set(char *s, t_str *data, bool mal)
{
	if (!data)
		return (-1);
	data->s = s;
	data->len = ft_strlen(data->s);
	data->i = 0;
	data->j = 0;
	data->mal = mal;
	return (1);
}

t_str	*ft_str_m_set(char *s, bool mal)
{
	t_str	*new;

	new = ft_calloc(1, sizeof(t_str));
	if (ft_str_set(s, new, mal) == -1)
		return (NULL);
	return (new);
}

int	ft_str_free(t_str *data)
{
	int	code;

	code = 0;
	if (data)
	{
		if (data->mal && data->s)
		{
			free(data->s);
			code = 1;
		}
		ft_bzero(data, sizeof(t_str));
		return (code);
	}
	return (-1);
}

int	ft_str_m_free(t_str *data)
{
	if (ft_str_free(data))
		return (-1);
	ft_free(data);
	return (1);
}

