#include <unistd.h>

int	main(void)
{
	int		i;
	char	lower;
	char	upper;

	i = 0;
	while (i < 26)
	{
		if (i % 2 == 0)
		{
			lower = 'a' + i;
			write(1, &lower, 1);
			write(1, &lower, 1);
		}
		else
		{
			upper = 'A' + i;
			write(1, &upper, 1);
			write(1, &upper, 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}