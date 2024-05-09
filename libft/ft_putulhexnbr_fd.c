/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulhexnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:55:24 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/09 18:35:06 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	do_putulhexnbr(unsigned long int n, int fd, char *digits, int *c_printed)
{
	char	digit;

	if (n == 0)
	{
		write(fd, "0", sizeof(char));
		(*c_printed) += 1;
		return (0);
	}
	else if (n / 16 != 0)
		do_putulhexnbr(n / 16, fd, digits, c_printed);
	digit = digits[n % 16];
	write(fd, &digit, sizeof(char));
	(*c_printed) += 1;
	return (0);
}

int	ft_putulhexnbr_fd(unsigned long int n, int fd, int uppercase)
{
	int		c_printed;
	char	*lower_hex_digits;
	char	*upper_hex_digits;

	lower_hex_digits = "0123456789abcdef";
	upper_hex_digits = "0123456789ABCDEF";
	c_printed = 0;
	if (uppercase)
		c_printed += do_putulhexnbr(n, fd, upper_hex_digits, &c_printed);
	else
		c_printed += do_putulhexnbr(n, fd, lower_hex_digits, &c_printed);
	return (c_printed);
}
