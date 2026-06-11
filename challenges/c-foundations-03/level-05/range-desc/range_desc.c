#include <stdlib.h>

int	*range_desc(int min, int max)
{
	int	*array;
	int	size;
	int	i;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = max - i;
		i++;
	}
	return (array);
}