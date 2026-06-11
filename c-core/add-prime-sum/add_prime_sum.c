#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

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

int	is_prime(int num)
{
	int	i;

	if (num <= 1)
		return (0);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	n;
	int	sum;
	int	i;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	n = ft_atoi(argv[1]);
	if (n <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	sum = 0;
	i = 2;
	while (i <= n)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}