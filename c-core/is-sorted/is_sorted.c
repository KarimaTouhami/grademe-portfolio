#include <stddef.h>

int	is_sorted(const int *a, size_t n)
{
	size_t	i;

	if (!a || n < 2)
		return (1);
	i = 1;
	while (i < n)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}
