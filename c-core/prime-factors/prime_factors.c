#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("wrong number of arguments\n");
		return (0);
	}

	int num = atoi(argv[1]);

	if (num <= 1)
	{
		if (num == 1)
			printf("1\n");
		else
			printf("\n");
		return (0);
	}

	int factor = 2;
	int first = 1;

	while (num > 1)
	{
		while (num % factor == 0)
		{
			if (!first)
				printf("*");
			
			printf("%d", factor);
			first = 0;
			
			num /= factor;
		}
		factor++;
	}
	printf("\n");

	return (0);
}