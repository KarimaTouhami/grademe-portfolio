#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

static int	write_all(const char *buf, size_t len)
{
	ssize_t w;

	if (len == 0)
		return (0);
	w = write (1, buf, len);
	if (w < 0)
		return (-1);
	return ((int)w);
}

static int print_str(const char *s)
{
	size_t	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	return (write_all(s, len));
}

static int printf_unsigned(unsigned long n, const char *digits, unsigned int base)
{
	char buf[32];
	int len;
	int i;

	len = 0;
	if (n == 0)
		buf[len++] = digits[0];
	while (n > 0)
	{
		buf[len++] = digits[n % base];
		n /= base;
	}
	i = len;
	while (i > 0)
	{
		i--;
		if (write_all(&buf[i], 1) < 0)
			return (-1);
	}
	return (len);
}

static int print_int(int n)
{
	unsigned long	u;
	int				prefix;
	int				digits;

	prefix = 0;
	if (n < 0)
	{
		if (write_all("-", 1) < 0)
			return (-1);
		prefix = 1;
		u = (unsigned long)(-(long)n);
	}
	else
		u = (unsigned long)n;
	digits = printf_unsigned(u, "0123456789", 10u);
	if (digits < 0)
		return (-1);
	return (prefix + digits);
}

static int print_conversion(char spec, va_list ap)
{
	unsigned char 	c;

	if (spec == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		return (write_all((const char *)&c, 1));
	}
	if (spec == 's')
		return (print_str(va_arg(ap, const char *)));
	if (spec == 'd')
		return (print_int(va_arg(ap, int)));
	if (spec == 'x')
		return (printf_unsigned(
			(unsigned long)va_arg(ap, unsigned int),
			"0123456789abcdef",
			16u
		));
	if (spec == '%')
		return (write_all("%", 1));
	if (write_all("%", 1) < 0 || write_all(&spec, 1) < 0)
		return (-1);
	return (2);
}

int	mini_printf(const char *format, ...)
{
	va_list ap;
	size_t i;
	int	count;
	int added;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			added = print_conversion(format[i + 1], ap);
			i += 2;
		}
		else
		{
			added = write_all(&format[i], 1);
			i++;
		}
		if (added < 0)
		{
			va_end(ap);
			return (-1);
		}
		count += added;
	}
	va_end(ap);
	return (count);
}