#include <unistd.h>

int	char_in_string(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	has_been_printed(char *str, char c, int current_index)
{
	int	i;

	i = 0;
	while (i < current_index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (char_in_string(argv[1], argv[2][i]))
		{
			if (!has_been_printed(argv[2], argv[2][i], i))
			{
				write(1, &argv[2][i], 1);
			}
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}