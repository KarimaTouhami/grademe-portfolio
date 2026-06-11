#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	a;
	int	b;
	int	temp;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	if (a <= 0 || b <= 0)
	{
		printf("\n");
		return (0);
	}
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	printf("%d\n", a);
	return (0);
}