#include <unistd.h>

static void	print_hex_row(unsigned char *ptr, unsigned int chunk)
{
	unsigned int	j;
	char			*hex;

	hex = "0123456789abcdef";
	j = 0;
	while (j < 16)
	{
		if (j < chunk)
		{
			write(1, &hex[ptr[j] >> 4], 1);
			write(1, &hex[ptr[j] & 0x0F], 1);
		}
		else
			write(1, "  ", 2);
		if (j < 15)
			write(1, " ", 1);
		j++;
	}
}

static void	print_ascii_row(unsigned char *ptr, unsigned int chunk)
{
	unsigned int	j;

	j = 0;
	while (j < chunk)
	{
		if (ptr[j] >= 32 && ptr[j] <= 126)
			write(1, &ptr[j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	*hex_dump(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	chunk;

	if (size == 0 || !addr)
		return (addr);
	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (size - i < 16)
			chunk = size - i;
		else
			chunk = 16;
		print_hex_row(&ptr[i], chunk);
		write(1, "  ", 2);
		print_ascii_row(&ptr[i], chunk);
		write(1, "\n", 1);
		i += chunk;
	}
	return (addr);
}