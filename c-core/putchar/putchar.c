#include <unistd.h>

int	gm_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}
