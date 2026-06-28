#include <unistd.h>
#include <stdlib.h>
#include "line_reader.h"

#ifndef READ_CHUNK_SIZE
# define READ_CHUNK_SIZE 42
#endif

static char	*append_char(char *line, char c, int len)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc(len + 2);
	if (!new_line)
		return (free(line), NULL);
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = c;
	new_line[i + 1] = '\0';
	free(line);
	return (new_line);
}

char	*read_next_line(int fd)
{
	char	*line;
	char	buf;
	int		bytes;
	int		len;

	if (fd < 0 || READ_CHUNK_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes = 1;
	len = 0;
	while (bytes > 0)
	{
		bytes = read(fd, &buf, 1);
		if (bytes < 0)
			return (free(line), NULL);
		if (bytes == 0)
			break ;
		line = append_char(line, buf, len++);
		if (!line)
			return (NULL);
		if (buf == '\n')
			break ;
	}
	return (line);
}