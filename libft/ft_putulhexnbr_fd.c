#include <unistd.h>

int	do_putulhexnbr(unsigned long int n, int fd, char *hex_digits, int *chars_printed)
{
	char	digit;

	if (n == 0)
	{
		write(fd, "0", sizeof(char));
		(*chars_printed) += 1;
		return (0);
	}
	else if (n / 16 != 0)
		do_putulhexnbr(n / 16, fd, hex_digits, chars_printed);
	digit = hex_digits[n % 16];
	write(fd, &digit, sizeof(char));
	(*chars_printed) += 1;
	return (0);
}

int	ft_putulhexnbr_fd(unsigned long int n, int fd, int uppercase)
{
	int	chars_printed;
	char	*lower_hex_digits;
	char	*upper_hex_digits;

	lower_hex_digits = "0123456789abcdef";
	upper_hex_digits = "0123456789ABCDEF";
	chars_printed = 0;
	if (uppercase)
		chars_printed += do_putulhexnbr(n, fd, upper_hex_digits, &chars_printed);
	else
		chars_printed += do_putulhexnbr(n, fd, lower_hex_digits, &chars_printed);
	return (chars_printed);
}
