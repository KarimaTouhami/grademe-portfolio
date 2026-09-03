#include <stdlib.h>
#include <unistd.h>

void	print_move(char src, char dest)
{
	write(1, &src, 1);
	write(1, " ", 1);
	write(1, &dest, 1);
	write(1, "\n", 1);
}

void	hanoi(int count, char src, char spare, char dest)
{
	if (count <= 0)
		return ;
	hanoi(count - 1, src, dest, spare);
	print_move(src, dest);
	hanoi(count - 1, spare, src, dest);
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (0);
	}
	n = atoi(argv[1]);
	if (n <= 0)
		return (0);
	hanoi(n, 'A', 'B', 'C');
	return (0);
}