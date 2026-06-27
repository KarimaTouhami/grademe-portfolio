#include <unistd.h>

static int	find_closing(char *code, int i)
{
	int	count;

	count = 1;
	while (count > 0)
	{
		i++;
		if (code[i] == '[')
			count++;
		else if (code[i] == ']')
			count--;
	}
	return (i);
}

static int	find_opening(char *code, int i)
{
	int	count;

	count = 1;
	while (count > 0)
	{
		i--;
		if (code[i] == ']')
			count++;
		else if (code[i] == '[')
			count--;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	unsigned char	tape[2048] = {0};
	unsigned char	*ptr;
	char			*code;
	int				i;

	if (argc != 2)
		return (0);
	code = argv[1];
	ptr = tape;
	i = 0;
	while (code[i])
	{
		if (code[i] == '>')
			ptr++;
		else if (code[i] == '<')
			ptr--;
		else if (code[i] == '+')
			(*ptr)++;
		else if (code[i] == '-')
			(*ptr)--;
		else if (code[i] == '.')
			write(1, ptr, 1);
		else if (code[i] == '[' && *ptr == 0)
			i = find_closing(code, i);
		else if (code[i] == ']' && *ptr != 0)
			i = find_opening(code, i);
		i++;
	}
	return (0);
}