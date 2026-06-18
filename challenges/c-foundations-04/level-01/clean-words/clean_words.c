#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		has_printed_word;
	int		in_whitespace_run;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	has_printed_word = 0;
	in_whitespace_run = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			in_whitespace_run = 1;
		}
		else
		{
			if (in_whitespace_run && has_printed_word)
			{
				write(1, " ", 1);
			}
			in_whitespace_run = 0;
			has_printed_word = 1;
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}