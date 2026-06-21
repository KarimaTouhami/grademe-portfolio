#include <stdlib.h>

int		*int_range(int from, int to)
{
	int		*range;
	int		i;

	if (from > to)
		range = (int *)malloc(sizeof(int) * (from - to) + 1);
	else
		range = (int *)malloc(sizeof(int) * (to - from) + 1);
	i = 0;
	while (from != to)
	{
		range[i++] = from;
		from += (from > to) ? -1 : 1;
	}
	range[i] = from;
	return (range);
}