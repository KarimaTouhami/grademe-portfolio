#include <stddef.h>

void	argsort_len(char **arr, size_t n, size_t *out)
{
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;
	size_t	k;

	if (!arr || !out || n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		out[i] = i;
		j = i;
		while (j > 0)
		{
			l1 = 0;
			while (arr[out[j - 1]][l1])
				l1++;
			l2 = 0;
			while (arr[out[j]][l2])
				l2++;
			if (l1 < l2)
				break ;
			if (l1 == l2)
			{
				k = 0;
				while (arr[out[j - 1]][k] && arr[out[j - 1]][k] == arr[out[j]][k])
					k++;
				if ((unsigned char)arr[out[j - 1]][k] <= (unsigned char)arr[out[j]][k])
					break ;
			}
			k = out[j];
			out[j] = out[j - 1];
			out[j - 1] = k;
			j--;
		}
		i++;
	}
}
