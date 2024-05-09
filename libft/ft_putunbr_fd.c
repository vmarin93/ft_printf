/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:53:46 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/09 17:53:47 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	do_putunbr(unsigned int n, int fd, int *chars_printed)
{
	char	digit;

	if (n / 10 != 0)
	{
		do_putunbr(n / 10, fd, chars_printed);
		do_putunbr(n % 10, fd, chars_printed);
	}
	else
	{
		digit = n + '0';
		write(fd, &digit, sizeof(char));
		(*chars_printed) += 1;
	}
	return (0);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	chars_printed;

	chars_printed = 0;
	chars_printed += do_putunbr(n, fd, &chars_printed);
	return (chars_printed);
}
