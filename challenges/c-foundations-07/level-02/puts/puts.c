#include <unistd.h>

int	ft_puts(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (i > 0)
	{
		if (write(1, s, i) == -1)
			return (-1);
	}
	if (write(1, "\n", 1) == -1)
		return (-1);
	return (0);
}