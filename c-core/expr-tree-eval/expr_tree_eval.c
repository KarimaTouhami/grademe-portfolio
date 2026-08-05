#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int	parse_expr(const char *s, int *i, int *err);

static int	parse_factor(const char *s, int *i, int *err)
{
	int	val;

	if (s[*i] == '\0')
	{
		*err = 1;
		return (0);
	}
	if (s[*i] == '(')
	{
		(*i)++;
		val = parse_expr(s, i, err);
		if (*err)
			return (0);
		if (s[*i] == ')')
			(*i)++;
		else if (s[*i] == '\0')
			*err = 1;
		else
		{
			printf("Invalid token '%c'\n", s[*i]);
			*err = 2;
		}
		return (val);
	}
	if (isdigit((unsigned char)s[*i]))
	{
		val = s[*i] - '0';
		(*i)++;
		return (val);
	}
	printf("Invalid token '%c'\n", s[*i]);
	*err = 2;
	return (0);
}

static int	parse_term(const char *s, int *i, int *err)
{
	int	left;
	int	right;

	left = parse_factor(s, i, err);
	if (*err)
		return (0);
	while (s[*i] == '*')
	{
		(*i)++;
		right = parse_factor(s, i, err);
		if (*err)
			return (0);
		left *= right;
	}
	return (left);
}

static int	parse_expr(const char *s, int *i, int *err)
{
	int	left;
	int	right;

	left = parse_term(s, i, err);
	if (*err)
		return (0);
	while (s[*i] == '+')
	{
		(*i)++;
		right = parse_term(s, i, err);
		if (*err)
			return (0);
		left += right;
	}
	return (left);
}

int	main(int argc, char **argv)
{
	int	i;
	int	err;
	int	res;

	if (argc != 2)
		return (1);
	i = 0;
	err = 0;
	res = parse_expr(argv[1], &i, &err);
	if (!err && argv[1][i] != '\0')
	{
		if (argv[1][i] == ')')
		{
			printf("Invalid token ')'\n");
			err = 2;
		}
		else if (isdigit((unsigned char)argv[1][i]))
		{
			printf("Invalid token '%c'\n", argv[1][i]);
			err = 2;
		}
		else
		{
			printf("Invalid token '%c'\n", argv[1][i]);
			err = 2;
		}
	}
	if (err == 1)
	{
		printf("Unexpected end\n");
		return (1);
	}
	if (err == 2)
		return (1);
	printf("%d\n", res);
	return (0);
}