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

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	const char	*start = nptr;
	long		result = 0;
	int			sign = 1;
	int			val;
	int			has_digits = 0;

	if (base < 0 || base == 1 || base > 36)
		return (0);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	
	if (base == 0)
	{
		if (*nptr == '0')
		{
			if (*(nptr + 1) == 'x' || *(nptr + 1) == 'X')
				base = 16;
			else
				base = 8;
		}
		else
			base = 10;
	}
	
	if (base == 16 && *nptr == '0' && (*(nptr + 1) == 'x' || *(nptr + 1) == 'X'))
		nptr += 2;
	
	while ((val = get_value(*nptr, base)) != -1)
	{
		result = result * base + val;
		has_digits = 1;
		nptr++;
	}
	
	if (endptr)
	{
		if (!has_digits)
			*endptr = (char *)start;
		else
			*endptr = (char *)nptr;
	}
	return (result * sign);
}