#include <unistd.h>

void	ft_shift_char(char c)
{
	if (c >= 'a' && c <= 'y')
		c += 1;
	else if (c == 'z')
		c = 'a';
	else if (c >= 'A' && c <= 'Y')
		c += 1;
	else if (c == 'Z')
		c = 'A';
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		ft_shift_char(argv[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}