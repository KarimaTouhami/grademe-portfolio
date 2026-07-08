#include <unistd.h>

static char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	i = 0;
	j = 0;
	while (argv[2][j] != '\0' && argv[1][i] != '\0')
	{
		if (to_lower(argv[1][i]) == to_lower(argv[2][j]))
			i++;
		j++;
	}
	if (argv[1][i] == '\0')
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}