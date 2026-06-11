#include <unistd.h>

void	show_bits(unsigned char octet)
{
	int	i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}