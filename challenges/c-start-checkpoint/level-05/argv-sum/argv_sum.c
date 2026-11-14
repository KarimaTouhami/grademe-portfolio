#include <unistd.h>

int		ft_atoi(char *s)
{
	int	i = 0;
	int sign = 1;
	int n = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	return (n * sign);
}

void put_num(int n)
{
	char c;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_num(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int i = 1;
	int sum = 0;

	while (i < argc)
	{
		sum += ft_atoi(argv[i]);
		i++;
	}
	put_num(sum);
	write(1, "\n", 1);
	return (0);
}
