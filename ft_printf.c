#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

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
				ft_putstr_fd(str, 1);
				chars_printed = ft_strlen(str);
			}
		//	else if (format[i + 1] == 'p')
		//	{
		//		ft_putchar_fd('0', 1);
		//		ft_putchar_fd('x', 1);
		//		chars_printed += 2;
		//		chars_printed += ft_putnbr_fd((uintptr_t)va_arg(args, uintptr_t), "0123456789abcdef", 1);
		//	}
		//	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		//	{
		//		chars_printed += ft_putnbr_fd(va_arg(args, int), "0123456789", 1);
		//	}
		//	i++;
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

int	main(void)
{
	printf("%d chars printed to the screen \n", ft_printf("%c \n", 'A'));
	printf("%d chars printed to the screen \n", printf("%c \n", 'A'));
	printf("\n\n");
	printf("%d chars printed to the screen \n", ft_printf("%s \n", "Hello!"));
	printf("%d chars printed to the screen \n", printf("%s \n", "Hello!"));
	printf("\n\n");
//	printf("%d chars printed to the screen \n", ft_printf("%d \n", 231));
//	printf("%d chars printed to the screen \n", printf("%d \n", 231));
//	printf("\n\n");
//	void	*ptr;
//
//	ptr = "";
//	printf("%d chars printed to the screen \n", ft_printf("%p \n", ptr));
//	printf("%d chars printed to the screen \n", printf("%p \n", ptr));
//	printf("\n\n");
//	printf("%d \n", 0x2A); 
//	ft_printf("%d \n", 0x2A);
}
