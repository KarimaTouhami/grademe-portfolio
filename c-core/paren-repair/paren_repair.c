#include <unistd.h>

void	mini_print(char c)
{
	write(1, &c, 1);
}

int	get_min_replacements(char *str)
{
	int	i;
	int	open;
	int	close;

	i = 0;
	open = 0;
	close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void	solve(char *str, char *out, int i, int balance, int spaces_left)
{
	if (balance < 0 || spaces_left < 0)
		return ;
	if (!str[i])
	{
		if (balance == 0 && spaces_left == 0)
		{
			out[i] = '\0';
			int j = 0;
			while (out[j])
				mini_print(out[j++]);
			mini_print('\n');
		}
		return ;
	}
	out[i] = ' ';
	solve(str, out, i + 1, balance, spaces_left - 1);

	out[i] = str[i];
	solve(str, out, i + 1, balance + (str[i] == '(' ? 1 : -1), spaces_left);
}

int	main(int argc, char **argv)
{
	char	out[2048];
	int		min_spaces;

	if (argc != 2)
		return (1);
	min_spaces = get_min_replacements(argv[1]);
	solve(argv[1], out, 0, 0, min_spaces);
	return (0);
}