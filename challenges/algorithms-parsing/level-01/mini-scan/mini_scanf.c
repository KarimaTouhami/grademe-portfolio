#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

static int	skip_input_whitespace(void)
{
	int	c;

	while (1)
	{
		c = fgetc(stdin);
		if (c == EOF)
			return (EOF);
		if (!isspace(c))
		{
			ungetc(c, stdin);
			break ;
		}
	}
	return (0);
}

static int	read_int(int *res, int *is_eof)
{
	int	c;
	int	sign;
	int	val;
	int	has_digits;

	sign = 1;
	val = 0;
	has_digits = 0;
	c = fgetc(stdin);
	if (c == EOF)
	{
		*is_eof = 1;
		return (0);
	}
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		c = fgetc(stdin);
	}
	while (c != EOF && isdigit(c))
	{
		val = val * 10 + (c - '0');
		has_digits = 1;
		c = fgetc(stdin);
	}
	if (c != EOF)
		ungetc(c, stdin);
	if (!has_digits)
		return (0);
	*res = val * sign;
	return (1);
}

static int	read_str(char *str, int *is_eof)
{
	int	c;
	int	len;

	len = 0;
	while (1)
	{
		c = fgetc(stdin);
		if (c == EOF)
		{
			if (len == 0)
				*is_eof = 1;
			break ;
		}
		if (isspace(c))
		{
			ungetc(c, stdin);
			break ;
		}
		str[len++] = (char)c;
	}
	str[len] = '\0';
	return (len > 0);
}

int	mini_scanf(const char *format, ...)
{
	va_list	args;
	int		f_idx;
	int		count;
	int		c;
	int		is_eof;

	va_start(args, format);
	f_idx = 0;
	count = 0;
	while (format[f_idx] != '\0')
	{
		if (isspace((unsigned char)format[f_idx]))
		{
			if (skip_input_whitespace() == EOF && count == 0)
			{
				va_end(args);
				return (EOF);
			}
			while (format[f_idx] != '\0' && isspace((unsigned char)format[f_idx]))
				f_idx++;
			continue ;
		}
		if (format[f_idx] == '%')
		{
			f_idx++;
			if (format[f_idx] == 'c')
			{
				c = fgetc(stdin);
				if (c == EOF)
				{
					va_end(args);
					return (count == 0 ? EOF : count);
				}
				*va_arg(args, char *) = (char)c;
				count++;
			}
			else if (format[f_idx] == 'd')
			{
				is_eof = 0;
				if (skip_input_whitespace() == EOF && count == 0)
				{
					va_end(args);
					return (EOF);
				}
				if (read_int(va_arg(args, int *), &is_eof))
					count++;
				else
				{
					va_end(args);
					return ((count == 0 && is_eof) ? EOF : count);
				}
			}
			else if (format[f_idx] == 's')
			{
				is_eof = 0;
				if (skip_input_whitespace() == EOF && count == 0)
				{
					va_end(args);
					return (EOF);
				}
				if (read_str(va_arg(args, char *), &is_eof))
					count++;
				else
				{
					va_end(args);
					return ((count == 0 && is_eof) ? EOF : count);
				}
			}
			f_idx++;
		}
		else
		{
			c = fgetc(stdin);
			if (c != format[f_idx])
			{
				if (c != EOF)
					ungetc(c, stdin);
				va_end(args);
				return (count == 0 && c == EOF ? EOF : count);
			}
			f_idx++;
		}
	}
	va_end(args);
	return (count);
}