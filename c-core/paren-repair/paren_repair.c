#include <unistd.h>

int	check(char *s)
{
	int	o;
	int	c;
	int	i;

	o = 0;
	c = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			o++;
		else if (s[i] == ')')
		{
			if (o > 0)
				o--;
			else
				c++;
		}
		i++;
	}
	return (o + c);
}

void	print_str(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	write(1, "\n", 1);
}

void	solve(char *s, int i, int o, int rem)
{
	if (o < 0)
		return ;
	if (!s[i])
	{
		if (!o && !rem)
			print_str(s);
		return ;
	}
	if (rem > 0)
	{
		char c = s[i];
		s[i] = ' ';
		solve(s, i + 1, o, rem - 1);
		s[i] = c;
	}
	if (s[i] == '(')
		solve(s, i + 1, o + 1, rem);
	else if (s[i] == ')')
		solve(s, i + 1, o - 1, rem);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	solve(av[1], 0, 0, check(av[1]));
	return (0);
}