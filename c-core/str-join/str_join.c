#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*str_join(char **parts, int n, char sep)
{
	char	*res;
	int		total_len;
	int		i;
	int		j;
	int		k;

	if (n <= 0 || !parts)
	{
		res = malloc(1);
		if (res)
			res[0] = '\0';
		return (res);
	}

	total_len = 0;
	i = 0;
	while (i < n)
	{
		total_len += ft_strlen(parts[i]);
		i++;
	}
	if (n > 1)
		total_len += (n - 1);

	res = malloc(total_len + 1);
	if (!res)
		return (NULL);

	k = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		if (parts[i])
		{
			while (parts[i][j])
				res[k++] = parts[i][j++];
		}
		if (i < n - 1)
			res[k++] = sep;
		i++;
	}
	res[k] = '\0';
	return (res);
}