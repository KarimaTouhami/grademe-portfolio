#include <unistd.h>

void	put_char(char *c)
{
	int	j = 0;
	while (c[j])
	{
		write(1, &c[j], 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc != 2)
		put_char("wrong number of arguments");
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 'n')
			{
				put_char("n\n");
				return (0);	
			}
			i++;
		}
	}
	put_char("\n");
	return (0);
}
