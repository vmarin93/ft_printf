/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:43:49 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/09 18:49:05 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	print_ptr(void *ptr)
{
	int	c_printed;

	c_printed = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		c_printed += 5;
	}
	else
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		c_printed += 2;
		c_printed += ft_putulhexnbr_fd((unsigned long int)ptr, 1, 0);
	}
	return (c_printed);
}
