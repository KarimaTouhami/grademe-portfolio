#include <unistd.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_title_case_str(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]))
		{
			new_word = 1;
			write(1, &str[i], 1);
		}
		else
		{
			if (new_word)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
				new_word = 0;
			}
			else
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
			}
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
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
		ft_title_case_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}