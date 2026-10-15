#include <stddef.h>

size_t	unique_sorted(int *a, size_t n)
{
	size_t	write_idx;
	size_t	read_idx;

	if (!a || n == 0)
		return (0);
	write_idx = 1;
	read_idx = 1;
	while (read_idx < n)
	{
		if (a[read_idx] != a[read_idx - 1])
		{
			a[write_idx] = a[read_idx];
			write_idx++;
		}
		read_idx++;
	}
	return (write_idx);
}