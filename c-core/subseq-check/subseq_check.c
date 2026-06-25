#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("wrong number of arguments\n");
		return (0);
	}

	char *s1 = argv[1];
	char *s2 = argv[2];
	int i = 0;
	int j = 0;

	while (s2[j] != '\0' && s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			i++;
		}
		j++;
	}

	if (s1[i] == '\0')
	{
		ft_putstr("yes\n");
	}
	else
	{
		ft_putstr("no\n");
	}

	return (0);
}