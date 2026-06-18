#include <stddef.h>

int	get_digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	parse_int_base(const char *str, int base)
{
	int	i;
	int	sign;
	int	result;
	int	digit;

	if (!str || base < 2 || base > 16)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0' && str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		digit = get_digit_value(str[i]);
		if (digit == -1 || digit >= base)
			break ;
		result = (result * base) + digit;
		i++;
	}
	return (result * sign);
}