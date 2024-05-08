#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	chars_printed;

	va_list	args;
	va_start(args, format);
	i = 0;
	chars_printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')	
			{
				ft_putchar_fd(va_arg(args, int), 1);
				chars_printed++;
			}
			else if (format[i + 1] == 's')
			{
				char	*str;
				str = va_arg(args, char *);
				if (str == NULL)
				{
					ft_putstr_fd("(null)", 1);
					chars_printed += 6;
				}
				else
				{
					ft_putstr_fd(str, 1);
					chars_printed += ft_strlen(str);
				}
			}
			else if (format[i + 1] == 'p')
			{
				void	*ptr;

				ptr = va_arg(args, void *);
				if (ptr == NULL)
				{
					ft_putstr_fd("(nil)", 1);
					chars_printed += 5;
				}
				else
				{
					ft_putchar_fd('0', 1);
					ft_putchar_fd('x', 1);
					chars_printed += 2;
					chars_printed += ft_putulhexnbr_fd((unsigned long int)ptr, 1, 0);
				}
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				chars_printed += ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i + 1] == 'u')
				chars_printed += ft_putunbr_fd(va_arg(args, unsigned int), 1);
			else if (format[i + 1] == 'x')
				chars_printed += ft_puthexnbr_fd(va_arg(args, unsigned int), 1, 0);
			else if (format[i + 1] == 'X')
				chars_printed += ft_puthexnbr_fd(va_arg(args, unsigned int), 1, 1);
			else if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				chars_printed++;
			}
			i++;
		}
		else 
		{
			ft_putchar_fd(format[i], 1);
			chars_printed++;
		}
		i++;
	}
	va_end(args);

	return (chars_printed);
}
