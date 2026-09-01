#include <stddef.h>

int	ranges_overlap(const void *a, size_t na, const void *b, size_t nb)
{
	char	*ptr_a;
	char	*ptr_b;

	if (na == 0 || nb == 0)
		return (0);
	ptr_a = (char *)a;
	ptr_b = (char *)b;
	if (ptr_a < ptr_b + nb && ptr_b < ptr_a + na)
		return (1);
	return (0);
}
