#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	col;
	int	spaces;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	col = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ')
		{
			spaces = 8 - (col % 8);
			col += spaces;
			while (spaces > 0)
			{
				write(1, " ", 1);
				spaces--;
			}
		}
		else
		{
			write(1, &argv[1][i], 1);
			col++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}