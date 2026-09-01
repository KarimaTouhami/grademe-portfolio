#include <limits.h>

int	add_overflows(int a, int b)
{
	if (b > 0 && a > INT_MAX - b)
		return (1);
	if (b < 0. && a < INT_MIN - b)
		return (1);
	return (0);
}
