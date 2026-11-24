#include <stdio.h>
#include <stdlib.h>

static unsigned int	calc_gcd(unsigned int a, unsigned int b)
{
	unsigned int	rem;

	while (b != 0)
	{
		rem = a % b;
		a = b;
		b = rem;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	unsigned int	a;
	unsigned int	b;

	if (argc != 3)
	{
		printf("wrong number of arguments\n");
		return (0);
	}
	a = (unsigned int)atoi(argv[1]);
	b = (unsigned int)atoi(argv[2]);
	printf("%u\n", calc_gcd(a, b));
	return (0);
}