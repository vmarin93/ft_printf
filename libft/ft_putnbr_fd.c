/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:33:42 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/01 18:30:37 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	do_putnbr(int n, int fd, int *chars_printed)
{
	char	digit;

	if (n == 0)
		chars_printed += write(fd, "0", sizeof(char));
	else if (n / 10 != 0)
	{
		do_putnbr(n / 10, fd, chars_printed);
		do_putnbr(n % 10, fd, chars_printed);
	}
	else
	{
		digit = -n + '0';
		write(fd, &digit, sizeof(char));
		(*chars_printed) += 1;
	}
	return (0);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	chars_printed;

	chars_printed = 0;
	if (n < 0)
		chars_printed += write(fd, "-", sizeof(char));
	if (n > 0)
		n *= -1;
	chars_printed += do_putnbr(n, fd, &chars_printed);
	return (chars_printed);
}
