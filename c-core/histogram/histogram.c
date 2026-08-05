#include <unistd.h>
#include <stdlib.h>

void	putchar_fd(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i, n, j;

	if (argc < 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		n = atoi(argv[i]);
		j = 0;
		while (j < n)
		{
			putchar_fd('#');
			j++;
		}
		putchar_fd('\n');
		i++;
	}
	return (0);
}