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
	int	end;
	int	start;

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
	if (i < 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	end = i;
	while (i >= 0 && !ft_is_space(argv[1][i]))
		i--;
	start = i + 1;
	while (start <= end)
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return (0);
}