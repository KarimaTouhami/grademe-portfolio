#include <stdlib.h>
#include <stdio.h>

void	dfs(int *nums, int count, int target, int i, int sum, int *sub, int s_idx)
{
	int	k;

	if (i == count)
	{
		if (sum == target)
		{
			k = 0;
			while (k < s_idx)
			{
				printf("%d", sub[k]);
				if (k < s_idx - 1)
					printf(" ");
				k++;
			}
			printf("\n");
		}
		return ;
	}
	sub[s_idx] = nums[i];
	dfs(nums, count, target, i + 1, sum + nums[i], sub, s_idx + 1);
	dfs(nums, count, target, i + 1, sum, sub, s_idx);
}

int	main(int argc, char **argv)
{
	int	nums[1024];
	int	sub[1024];
	int	i;

	if (argc < 3)
		return (1);
	i = 0;
	while (i < argc - 2)
	{
		nums[i] = atoi(argv[i + 2]);
		i++;
	}
	dfs(nums, argc - 2, atoi(argv[1]), 0, 0, sub, 0);
	return (0);
}