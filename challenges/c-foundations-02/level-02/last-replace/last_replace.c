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
	int		i;
	char	search;
	char	replace;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[2][0] == '\0' || argv[2][1] != '\0' || \
		argv[3][0] == '\0' || argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	search = argv[2][0];
	replace = argv[3][0];
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		if (argv[1][i] == search)
		{
			argv[1][i] = replace;
			break ;
		}
		i--;
	}
	ft_putstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}