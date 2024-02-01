/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:03:57 by anboisve          #+#    #+#             */
/*   Updated: 2023/11/25 18:18:12 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_err_len(size_t i)
{
	char	*print;

	print = NULL;
	print = ft_strfjoin(print, "\x1B[31m");
	while (i--)
		print = ft_strfjoin(print, "~");
	print = ft_strfjoin(print, "^\x1B[37m");
	ft_printf(2, "%o%s\n", NULL, print);
	ft_free(print);
}
