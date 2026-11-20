#include <stdlib.h>

static size_t	span(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*build_path(const char *dir, const char *name)
{
	size_t	dir_len;
	size_t	name_len;
	size_t	head_len;
	size_t	i;
	char	*head;
	char	*out;

	if (dir == NULL || name == NULL)
		return (NULL);
	dir_len = span(dir);
	name_len = span(name);
	head = malloc(dir_len + 2);
	if (head == NULL)
		return (NULL);
	i = 0;
	while (i < dir_len)
	{
		head[i] = dir[i];
		i++;
	}
	if (dir_len > 0 && dir[dir_len - 1] != '/')
		head[i++] = '/';
	head[i] = '\0';
	head_len = i;
	out = malloc(head_len + name_len + 1);
	if (out == NULL)
	{
		free(head);
		return (NULL);
	}
	i = 0;
	while (i < head_len)
	{
		out[i] = head[i];
		i++;
	}
	i = 0;
	while (i < name_len)
	{
		out[head_len + i] = name[i];
		i++;
	}
	out[head_len + name_len] = '\0';
	free(head);
	return (out);
}
