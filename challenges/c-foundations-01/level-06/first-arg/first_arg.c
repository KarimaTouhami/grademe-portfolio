#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int		len;

	if (argc < 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}

	len = 0;
	while (argv[1][len])
		len++;
	write(1, argv[1], len);
	write(1, "\n", 1);
	return (0);
}
