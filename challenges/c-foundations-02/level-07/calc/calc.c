#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;
	char	op;

	if (argc != 4 || argv[2][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = argv[2][0];
	if (op == '+')
		ft_putnbr(a + b);
	else if (op == '-')
		ft_putnbr(a - b);
	else if (op == '*')
		ft_putnbr(a * b);
	else if (op == '/' && b != 0)
		ft_putnbr(a / b);
	else if (op == '%' && b != 0)
		ft_putnbr(a % b);
	write(1, "\n", 1);
	return (0);
}