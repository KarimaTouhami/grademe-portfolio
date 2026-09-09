#include <stddef.h>

void	row_sums(const int (*rows)[4], size_t nrows, int *out)
{
	size_t	i;

	if (nrows == 0)
		return ;
	i = 0;
	while (i < nrows)
	{
		out[i] = rows[i][0] + rows[i][1] + rows[i][2] + rows[i][3];
		i++;
	}
}