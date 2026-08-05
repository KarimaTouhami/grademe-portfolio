#include <stddef.h>

void	reverse_int(int *a, size_t n)
{
	int 	i;
	int 	j;
	int 	tmp;

	if (n == 0)
		return ;

	i = 0;
	j = n - 1;
	while (i < j)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++;
		j--;
	}
}
