#include <unistd.h>

static void	ft_putnbr(int n)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

static int	do_op(int *stack, int *top, char op)
{
	if (*top < 2)
		return (0);
	if (op == '+')
		stack[*top - 2] = stack[*top - 2] + stack[*top - 1];
	else if (op == '-')
		stack[*top - 2] = stack[*top - 2] - stack[*top - 1];
	else if (op == '*')
		stack[*top - 2] = stack[*top - 2] * stack[*top - 1];
	else if (op == '/')
	{
		if (stack[*top - 1] == 0)
			return (0);
		stack[*top - 2] = stack[*top - 2] / stack[*top - 1];
	}
	else if (op == '%')
	{
		if (stack[*top - 1] == 0)
			return (0);
		stack[*top - 2] = stack[*top - 2] % stack[*top - 1];
	}
	(*top)--;
	return (1);
}

int	main(int argc, char **argv)
{
	int		stack[1000];
	int		top;
	int		i;
	long	num;

	if (argc != 2)
		return (write(1, "Error\n", 6), 0);
	top = 0;
	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (!argv[1][i])
			break;

		if ((argv[1][i] >= '0' && argv[1][i] <= '9') || 
			(argv[1][i] == '-' && argv[1][i + 1] >= '0' && argv[1][i + 1] <= '9'))
		{
			int sign = 1;
			if (argv[1][i] == '-')
			{
				sign = -1;
				i++;
			}
			num = 0;
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				num = num * 10 + (argv[1][i] - '0');
				i++;
			}
			stack[top++] = num * sign;
		}

		else if (argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || 
				 argv[1][i] == '/' || argv[1][i] == '%')
		{
			if (!do_op(stack, &top, argv[1][i]))
				return (write(1, "Error\n", 6), 0);
			i++;
		}
		else
			return (write(1, "Error\n", 6), 0);
	}
	if (top != 1)
		return (write(1, "Error\n", 6), 0);
	ft_putnbr(stack[0]);
	write(1, "\n", 1);
	return (0);
}