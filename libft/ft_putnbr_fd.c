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
#include "libft.h"

static void	do_putnbr(long n, int base, char *base_digits, int fd)
{
	if (n == 0)
		write(fd, "0", sizeof(char));
	else if (n / 10 != 0)
	{
		do_putnbr(n / base, base, base_digits, fd);
		do_putnbr(n % base, base, base_digits, fd);
	}
	else
	{
		write(fd, &base_digits[n], sizeof(char));
	}
}

void	ft_putnbr_fd(long n, char *base_digits, int fd)
{
	int	base;

	base = ft_strlen(base_digits);
	if (base == 16)
		do_putnbr(n, base, base_digits, fd);
	else
	{
		if (n < 0)
			write(fd, "-", sizeof(char));
		if (n > 0)
			n *= -1;
		do_putnbr(n, base, base_digits, fd);
	}
}
