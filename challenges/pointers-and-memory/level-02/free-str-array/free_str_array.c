#include <stdlib.h>

int	free_str_array(char **arr)
{
	int	count;

	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		count++;
	}
	free(arr);
	return (count);
}
