#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	col;
	int	spaces_to_print;

	if (argc != 2)
	{
		ft_putstr("wrong number of arguments\n");
		return (0);
	}
	i = 0;
	col = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ')
		{
			spaces_to_print = 8 - (col % 8);
			while (spaces_to_print > 0)
			{
				write(1, " ", 1);
				col++;
				spaces_to_print--;
			}
		}
		else
		{
			write(1, &argv[1][i], 1);
			col++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}