#include <unistd.h>

int	char_in_str(char c, char *str)
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

int	main(int argc, char *argv[])
{
	int	i;
	int	seen[256];

	if (argc != 2 && argc == 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (i < 256)
	{
		seen[i] = 0;
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		char c = argv[2][i];
		if (char_in_str(c, argv[1]) && seen[(unsigned char)c] == 0)
		{
			write(1, &c, 1);
			seen[(unsigned char)c] = 1; // Mark as printed
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}