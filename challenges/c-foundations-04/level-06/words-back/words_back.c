#include <stdlib.h>
#include <unistd.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t');
}

static void	print_rev(const char *s)
{
	int	i;
	int	end;

	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		end = i;
		while (i > 0 && !is_sep(s[i - 1]))
			i--;
		write(1, s + i, (size_t)(end - i));
		if (i > 0)
		{
			write(1, " ", 1);
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "wrong number of arguments\n", 26);
	else
	{
		if (argv[1][0])
			print_rev(argv[1]);
		write(1, "\n", 1);
	}
	return (0);
}