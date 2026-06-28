#include <unistd.h>

static void	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		put_str("wrong number of arguments");
		return (0);
	}
	i = 0;
	j = 0;
	while (argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
			i++;
		if (argv[1][i] == '\0')
			break ;
		j++;
	}
	if (argv[1][i] == '\0')
		put_str("yes");
	else
		put_str("no");
	return (0);
}