/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:48:51 by anboisve          #+#    #+#             */
/*   Updated: 2023/10/17 15:32:00 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief put all the memory to zero the size of n
/// @param s input
/// @param n size of byte
void	ft_bzero(void *s, size_t n)
{
	while (s && n--)
		((char *)s)[n] = 0;
}
