/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:37:37 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/09 18:43:20 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	print_string(char *str)
{
	int	c_printed;

	c_printed = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		c_printed += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		c_printed += ft_strlen(str);
	}
	return (c_printed);
}
