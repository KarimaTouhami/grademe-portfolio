#include <stddef.h>

int	at_or_default(const int *a, size_t n, long i, int fallback)
{
	if (i < 0 || (size_t)i >= n)
		return (fallback);
	return (a[i]);
}