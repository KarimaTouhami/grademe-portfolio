#include <unistd.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	print_word(char *str, int start, int end)
{
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	word_end;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		word_end = i;
		while (i >= 0 && !ft_is_space(argv[1][i]))
			i--;
		print_word(argv[1], i + 1, word_end);
		if (i > 0)
			write(1, " ", 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}