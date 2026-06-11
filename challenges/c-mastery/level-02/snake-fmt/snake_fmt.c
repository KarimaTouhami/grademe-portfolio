#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			if (i > 0)
				write(1, "_", 1);
			char c = argv[1][i] + 32;
			write(1, &c, 1);
		}
		else
		{
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}