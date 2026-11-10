#include <unistd.h>

// Print n in decimal on standard output, with no newline.
// n is between 0 and INT_MAX.
void	put_number(int n)
{
	long	nb;

	nb = (long) n;

	if (nb >= 10)
		put_number(n / 10);
	char digit = (nb % 10) + '0'; 
	write(1, &digit, 1);
}
