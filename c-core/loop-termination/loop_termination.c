#include <stddef.h>

size_t	count_steps(unsigned int start)
{
	size_t	steps;

	steps = 0;
	while (start > 0)
	{
		start /= 2;
		steps++;
	}
	return (steps);
}