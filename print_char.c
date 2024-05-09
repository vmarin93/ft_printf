/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:36:19 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/09 19:37:09 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	print_char(int c)
{
	int	c_printed;

	c_printed = 0;
	ft_putchar_fd(c, 1);
	c_printed++;
	return (c_printed);
}
