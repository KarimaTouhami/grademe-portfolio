#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 8192

static int	write_stars(size_t len)
{
	char	stars[256];
	size_t	i;
	size_t	chunk;

	i = 0;
	while (i < 256)
		stars[i++] = '*';
	while (len > 0)
	{
		chunk = (len > 256) ? 256 : len;
		if (write(1, stars, chunk) < 0)
		{
			perror("write");
			return (-1);
		}
		len -= chunk;
	}
	return (0);
}

static int	process_stream(const char *pat, size_t pat_len)
{
	char	buf[BUF_SIZE];
	size_t	buf_len;
	ssize_t	bytes;
	char	*match;
	size_t	i;
	size_t	safe_len;

	buf_len = 0;
	while ((bytes = read(0, buf + buf_len, BUF_SIZE - buf_len)) > 0)
	{
		buf_len += bytes;
		i = 0;
		while (i + pat_len <= buf_len)
		{
			match = memmem(buf + i, buf_len - i, pat, pat_len);
			if (match)
			{
				if (match > buf + i && write(1, buf + i, match - (buf + i)) < 0)
				{
					perror("write");
					return (1);
				}
				if (write_stars(pat_len) < 0)
					return (1);
				i = (match - buf) + pat_len;
			}
			else
			{
				safe_len = buf_len - i - (pat_len - 1);
				if (safe_len > 0)
				{
					if (write(1, buf + i, safe_len) < 0)
					{
						perror("write");
						return (1);
					}
					i += safe_len;
				}
				break ;
			}
		}
		if (i > 0)
		{
			memmove(buf, buf + i, buf_len - i);
			buf_len -= i;
		}
	}
	if (bytes < 0)
	{
		perror("read");
		return (1);
	}
	if (buf_len > 0 && write(1, buf, buf_len) < 0)
	{
		perror("write");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1] || argv[1][0] == '\0')
		return (1);
	if (process_stream(argv[1], strlen(argv[1])) != 0)
		return (1);
	return (0);
}