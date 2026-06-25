#include <stddef.h>

void	*memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		target;
	size_t				i;

	src = (const unsigned char *)s;
	target = (unsigned char)c;
	i = 0;

	while (i < n)
	{
		if (src[i] == target)
		{
			return ((void *)&src[i]);
		}
		i++;
	}

	return (NULL);
}