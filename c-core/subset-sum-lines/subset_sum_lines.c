#include <stdio.h>
#include <stdlib.h>

static void	print_subset(int *source, int *selected, int size)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (i < size)
	{
		if (selected[i])
		{
			if (!first)
				printf(" ");
			printf("%d", source[i]);
			first = 0;
		}
		i++;
	}
	printf("\n");
}

static void	find_subsets(int *src, int *sel, int size, int idx, int target)
{
	if (idx == size)
	{
		if (target == 0)
			print_subset(src, sel, size);
		return ;
	}

	sel[idx] = 1;
	find_subsets(src, sel, size, idx + 1, target - src[idx]);

	sel[idx] = 0;
	find_subsets(src, sel, size, idx + 1, target);
}

int	main(int argc, char **argv)
{
	int	target;
	int	size;
	int	*source;
	int	*selected;
	int	i;

	if (argc < 2)
		return (1);
		
	target = atoi(argv[1]);
	size = argc - 2;

	if (size == 0)
	{
		if (target == 0)
		{
			printf("\n");
			return (0);
		}
		return (1); 
	}
	
	source = malloc(sizeof(int) * size);
	selected = calloc(size, sizeof(int));
	if (!source || !selected)
		return (1);
		
	i = 0;
	while (i < size)
	{
		source[i] = atoi(argv[i + 2]);
		i++;
	}
	
	find_subsets(source, selected, size, 0, target);
	
	free(source);
	free(selected);
	return (0);
}