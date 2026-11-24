#include <unistd.h>

static long	parse_long(const char *s)
{
	int		i;
	long	sign;
	long	val;

	i = 0;
	sign = 1;
	val = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		val = val * 10 + (s[i] - '0');
		i++;
	}
	return (val * sign);
}

static void	put_long(long n)
{
	unsigned long	u;
	char			buf[32];
	int				i;

	if (n < 0)
	{
		write(1, "-", 1);
		u = (unsigned long)(-(n + 1)) + 1;
	}
	else
		u = (unsigned long)n;
	i = 0;
	if (u == 0)
		buf[i++] = '0';
	while (u > 0)
	{
		buf[i++] = (char)('0' + (u % 10));
		u /= 10;
	}
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	long	sum;

	i = 1;
	sum = 0;
	while (i < argc)
	{
		sum += parse_long(argv[i]);
		i++;
	}
	put_long(sum);
	write(1, "\n", 1);
	return (0);
}