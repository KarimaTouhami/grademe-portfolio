#include <stdlib.h>

int	*range_desc(int min, int max)
{
	int		*arr;
	long	size;
	long	i;
	long	current;

	if (min > max)
		return (NULL);
	size = (long)max - (long)min + 1;
	arr = (int *)malloc(sizeof(int) * (size_t)size);
	if (!arr)
		return (NULL);
	i = 0;
	current = (long)max;
	while (i < size)
	{
		arr[i] = (int)current;
		current--;
		i++;
	}
	return (arr);
}