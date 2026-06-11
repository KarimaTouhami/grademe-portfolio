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

int	main(int argc, char *argv[])
{
	int	i;
	int	last_match;

	if (argc != 4 || argv[2][1] != '\0' || argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	last_match = -1;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == argv[2][0])
			last_match = i;
		i++;
	}
	if (last_match != -1)
		argv[1][last_match] = argv[3][0];
	ft_putstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}