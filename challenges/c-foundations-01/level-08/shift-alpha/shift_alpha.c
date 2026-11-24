#include <unistd.h>

static void	put_str(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static char	shift_char(char c)
{
	if (c >= 'a' && c <= 'y')
		return (c + 1);
	if (c == 'z')
		return ('a');
	if (c >= 'A' && c <= 'Y')
		return (c + 1);
	if (c == 'Z')
		return ('A');
	return (c);
}

int	main(int argc, char **argv)
{
	int		i;
	char	shifted;

	if (argc != 2)
	{
		put_str("wrong number of arguments\n");
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		shifted = shift_char(argv[1][i]);
		write(1, &shifted, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}