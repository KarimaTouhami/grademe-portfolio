#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	put_number(int n)
{
	long	nb;

	nb = (long) n;

	if (nb >= 10)
		put_number(n / 10);
	char digit = (nb % 10) + '0'; 
	write(1, &digit, 1);
}

// argv[1] holds only decimal digits, worth 0 to 1000000000.
// Print twice that value, then a newline.
int	main(int argc, char **argv)
{
	int		i;
	int		number;
	i = 0;
	number  = 0;
	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return (0);
	}
	if (argc == 2)
	{
		while (argv[1][i])
		{
			number = number * 10 + (argv[1][i] - '0');
			i++;
		}
		number *= 2;
		put_number(number);
	}
	write(1, "\n", 1);
	return (0);
}
