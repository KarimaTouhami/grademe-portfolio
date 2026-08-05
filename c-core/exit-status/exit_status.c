#include <unistd.h>
#include <limits.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	parse_int(const char *str, int *val)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!is_digit(str[i]))
		return (2);
	res = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (2);
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && (-res) < INT_MIN))
			return (3);
		i++;
	}
	*val = (int)(res * sign);
	return (0);
}

void	ft_putnbr(int n)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr((int)(nb / 10));
	c = (char)('0' + (nb % 10));
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		val;
	int		ret;
	long	sum;

	if (argc < 2)
		return (1);
	sum = 0;
	i = 1;
	while (i < argc)
	{
		ret = parse_int(argv[i], &val);
		if (ret != 0)
			return (ret);
		sum += val;
		if (sum > INT_MAX || sum < INT_MIN)
			return (3);
		i++;
	}
	ft_putnbr((int)sum);
	write(1, "\n", 1);
	return (0);
}