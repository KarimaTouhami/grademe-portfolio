#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	show_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((octet >> i) & 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		i--;
	}
}