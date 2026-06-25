#include <stdlib.h>

static int	get_len(unsigned int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*int_to_str_base(int value, int base)
{
	if (base < 2 || base > 16)
		return (NULL);

	char			*base_digits = "0123456789abcdef";
	unsigned int	nbr;
	int				len;
	int				is_negative;
	char			*str;

	is_negative = 0;
	if (base == 10 && value < 0)
	{
		is_negative = 1;
		nbr = (unsigned int)(-value);
	}
	else
	{
		nbr = (unsigned int)value;
	}

	len = get_len(nbr, base) + is_negative;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	str[len] = '\0';

	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}

	while (nbr > 0)
	{
		len--;
		str[len] = base_digits[nbr % base];
		nbr /= base;
	}

	if (is_negative)
		str[0] = '-';

	return (str);
}