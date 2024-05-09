/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:00:35 by vmarin            #+#    #+#             */
/*   Updated: 2024/05/09 19:30:43 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	handle_specifiers(const char specifier, va_list args, size_t *c_printed)
{
	if (specifier == 'c')
		*c_printed += print_char(va_arg(args, int));
	else if (specifier == 's')
		*c_printed += print_string(va_arg(args, char *));
	else if (specifier == 'p')
		*c_printed += print_ptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		*c_printed += ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 'u')
		*c_printed += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (specifier == 'x')
		*c_printed += ft_puthexnbr_fd(va_arg(args, unsigned int), 1, 0);
	else if (specifier == 'X')
		*c_printed += ft_puthexnbr_fd(va_arg(args, unsigned int), 1, 1);
	else if (specifier == '%')
	{
		ft_putchar_fd('%', 1);
		*c_printed += 1;
	}
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	c_printed;
	va_list	args;

	i = 0;
	c_printed = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			handle_specifiers(format[i + 1], args, &c_printed);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			c_printed++;
		}
		i++;
	}
	va_end(args);
	return (c_printed);
}
