#include <unistd.h>

/*
** Checks if a character exists anywhere inside the first string.
*/
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

int	main(int argc, char **argv)
{
	int	i;
	int	already_printed[256];

	if (argc == 3)
	{
		// Initialize the lookup table tracking array to 0
		i = 0;
		while (i < 256)
		{
			already_printed[i] = 0;
			i++;
		}
		// Iterate through the second string
		i = 0;
		while (argv[2][i] != '\0')
		{
			// Cast to unsigned char to safely handle any extended ASCII indices
			unsigned char c = (unsigned char)argv[2][i];

			if (char_in_str(c, argv[1]) && !already_printed[c])
			{
				write(1, &c, 1);
				already_printed[c] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}