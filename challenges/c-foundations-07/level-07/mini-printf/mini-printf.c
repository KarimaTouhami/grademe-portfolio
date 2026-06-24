#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-', count);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10, count);
	ft_putchar((num % 10) + '0', count);
}

void	ft_puthex(unsigned int n, int *count)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16, count);
	ft_putchar(hex_digits[n % 16], count);
}

void	handle_format(char specifier, va_list ap, int *count)
{
	if (specifier == 'c')
		ft_putchar((char)va_arg(ap, int), count);
	else if (specifier == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (specifier == 'd')
		ft_putnbr(va_arg(ap, int), count);
	else if (specifier == 'x')
		ft_puthex(va_arg(ap, unsigned int), count);
	else if (specifier == '%')
		ft_putchar('%', count);
	else
	{
		ft_putchar('%', count);
		ft_putchar(specifier, count);
	}
}

int	mini_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!format)
		return (0);
	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			handle_format(format[i + 1], ap, &count);
			i += 2;
		}
		else
		{
			ft_putchar(format[i], &count);
			i++;
		}
	}
	va_end(ap);
	return (count);
}