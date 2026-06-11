#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	last_e_index;

	if (argc != 2)
	{
		write(1, "e\n", 2);
		return (0);
	}
	i = 0;
	last_e_index = -1;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == 'e')
			last_e_index = i;
		i++;
	}
	if (last_e_index != -1)
		write(1, &argv[1][last_e_index], 1);
	write(1, "\n", 1);
	return (0);
}