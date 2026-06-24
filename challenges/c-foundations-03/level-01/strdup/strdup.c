#include <stdlib.h>
int	len(char *s)
{
	int	j;

	j = 0;
	while (s[j])
		j++;
	return (j);
}

char	*strdup(char *src)
{
	int	i;
	int	l;
	char	*arr;

	i = 0;
	l = len(src);
	arr = malloc (l + 1);
	if (arr == NULL)
		return (NULL);
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}