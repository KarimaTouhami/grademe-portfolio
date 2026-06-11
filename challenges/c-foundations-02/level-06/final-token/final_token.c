#include <unistd.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	word_end;
	int	word_start;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	i--;
	while (i >= 0 && ft_is_space(argv[1][i]))
		i--;
	word_end = i;
	while (i >= 0 && !ft_is_space(argv[1][i]))
		i--;
	word_start = i + 1;
	while (word_start <= word_end && word_end >= 0)
	{
		write(1, &argv[1][word_start], 1);
		word_start++;
	}
	write(1, "\n", 1);
	return (0);
}