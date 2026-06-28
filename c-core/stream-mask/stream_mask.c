#include <unistd.h>
#include <string.h>

static int	stream_match(const char *win, const char *token, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (win[i] != token[i])
			return (0);
		i++;
	}
	return (1);
}

static void	print_stars(size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(1, "*", 1);
		i++;
	}
}

static int	process_stream(const char *token, size_t t_len)
{
	char	win[4096];
	char	c;
	size_t	w_len;
	ssize_t	ret;

	w_len = 0;
	while (1)
	{
		ret = read(0, &c, 1);
		if (ret < 0)
			return (write(2, "Error\n", 6), 1);
		if (ret == 0)
			break ;
		win[w_len++] = c;
		if (w_len == t_len)
		{
			if (stream_match(win, token, t_len))
			{
				print_stars(t_len);
				w_len = 0;
			}
			else
			{
				write(1, &win[0], 1);
				memmove(win, win + 1, --w_len);
			}
		}
	}
	if (w_len > 0)
		write(1, win, w_len);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*token;
	size_t	t_len;

	if (argc != 2)
		return (1);
	token = argv[1];
	t_len = strlen(token);
	if (t_len == 0 || t_len > 4096)
		return (1);
	return (process_stream(token, t_len));
}