#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int 	i, j, n;

	if (argc == 1)
		return (write(1, "wrong number of arguments\n", 26), 0);

	i = 1;
	while (i < argc)
	{
		n = atoi(argv[i]);
		j = 0;
		while (j < n)
		{
			write (1, "#", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
