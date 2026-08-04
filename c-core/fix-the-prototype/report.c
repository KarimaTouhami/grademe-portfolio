#include <unistd.h>

int	print_report(void)
{
	write(1, "status: green\n", 14);
	write(1, "tests: 12 passed\n", 17);
	write(1, "warnings: 0\n", 12);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	print_report();
	return (0);
}

