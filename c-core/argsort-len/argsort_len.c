#include <stddef.h>

void	argsort_len(char **arr, size_t n, size_t *out)
{
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;
	size_t	k;
	size_t	tmp;
	int		swap;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		out[i] = i;
		i++;
	}
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			l1 = 0;
			while (arr[out[j]][l1])
				l1++;
			l2 = 0;
			while (arr[out[j + 1]][l2])
				l2++;
			swap = (l1 > l2);
			if (l1 == l2)
			{
				k = 0;
				while (arr[out[j]][k] && arr[out[j]][k] == arr[out[j + 1]][k])
					k++;
				if ((unsigned char)arr[out[j]][k] != (unsigned char)arr[out[j + 1]][k])
					swap = ((unsigned char)arr[out[j]][k] > (unsigned char)arr[out[j + 1]][k]);
				else
					swap = (out[j] > out[j + 1]);
			}
			if (swap)
			{
				tmp = out[j];
				out[j] = out[j + 1];
				out[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}