#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	int		i = 0;
	while (s[i])
		i++;
	return (i);
}

// Copies src into dst, a buffer of cap bytes, without writing past it.
// Returns the length of src.
size_t	copy_capped(char *dst, const char *src, size_t cap)
{
	size_t j;
	size_t k;
	size_t size;

	j = 0;
	k = 0;
	size = ft_strlen(src);
	if (cap == 0)
		return (size);
	while(src[j] && k < cap - 1)
	{
		dst[k] = src[j];
		k++;
		j++;
	}
	dst[k] = '\0';
	return (size);
}
