#include <stddef.h>

size_t	prefix_span(const char *text, const char *allowed)
{
	size_t	i;
	size_t	j;
	int		found;

	if (!text || !allowed)
		return (0);
	i = 0;

	while (text[i] != '\0')
	{
		j = 0;
		found = 0;

		while (allowed[j] != '\0')
		{
			if (text[i] == allowed[j])
			{
				found = 1;
				break ;
			}
			j++;
		}

		if (found == 0)
			break ;
		i++;
	}
	return (i);
}