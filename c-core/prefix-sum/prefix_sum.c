#include <stddef.h>

void	prefix_sum(const int *a, size_t n, long *out)
{
	size_t 	i;
	long 	sum;

	if (n == 0)
		return ;
	sum = 0;
	i = 0;
	while (i < n)
	{
		sum += (long)a[i];
		out[i] = sum;
		i++;
	}
}
