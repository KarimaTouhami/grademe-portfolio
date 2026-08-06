#include <limits.h>

int	safe_div(int a, int b, int *out)
{
	if ((b == 0) || (b == -1 && a == INT_MIN))
		return (-1);
	*out = a / b;
	return (0);
}
