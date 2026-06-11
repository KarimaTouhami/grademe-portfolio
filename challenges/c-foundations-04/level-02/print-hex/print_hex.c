#include <unistd.h>

unsigned int	ft_atoi_unsigned(char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_print_hex(unsigned int n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	main(int argc, char *argv[])
{
	unsigned int	num;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[1][0] == '-')
	{
		write(1, "\n", 1);
		return (0);
	}
	num = ft_atoi_unsigned(argv[1]);
	ft_print_hex(num);
	write(1, "\n", 1);
	return (0);
}