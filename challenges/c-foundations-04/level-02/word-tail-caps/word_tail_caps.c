#include <unistd.h>

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

int	is_last_alpha_in_word(char *str, int i)
{
	if (!is_alpha(str[i]))
		return (0);
	i++;
	while (str[i] != '\0' && !is_whitespace(str[i]))
	{
		if (is_alpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	process_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]))
		{
			if (is_last_alpha_in_word(str, i))
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
			else
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		process_argument(argv[i]);
		i++;
	}
	return (0);
}