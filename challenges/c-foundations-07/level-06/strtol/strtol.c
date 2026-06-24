#include <stddef.h>

static int	get_value(char c, int base)
{
	if (c >= '0' && c <= '9' && (c - '0') < base)
		return (c - '0');
	if (base > 10 && c >= 'a' && c <= 'z' && (c - 'a' + 10) < base)
		return (c - 'a' + 10);
	if (base > 10 && c >= 'A' && c <= 'Z' && (c - 'A' + 10) < base)
		return (c - 'A' + 10);
	return (-1);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	const char	*start = str;
	long		result = 0;
	int			sign = 1;
	int			val;
	int			has_digits = 0;

	if (base < 0 || base == 1 || base > 36)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (base == 0)
	{
		if (*str == '0')
		{
			if (*(str + 1) == 'x' || *(str + 1) == 'X')
				base = 16;
			else
				base = 8;
		}
		else
			base = 10;
	}
	if (base == 16 && *str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while ((val = get_value(*str, base)) != -1)
	{
		result = result * base + val;
		has_digits = 1;
		str++;
	}
	if (endptr)
	{
		if (!has_digits)
			*endptr = (char *)start;
		else
			*endptr = (char *)str;
	}
	return (result * sign);
}