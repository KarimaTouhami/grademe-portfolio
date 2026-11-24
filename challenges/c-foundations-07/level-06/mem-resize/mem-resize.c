#include <stddef.h>
#include <stdlib.h>

void	*mem_resize(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*dst;
	const unsigned char	*src;
	size_t				copy_len;
	size_t				i;

	dst = (unsigned char *)malloc(new_size);
	if (!dst)
		return (NULL);
	if (ptr)
	{
		src = (const unsigned char *)ptr;
		copy_len = (old_size < new_size) ? old_size : new_size;
		i = 0;
		while (i < copy_len)
		{
			dst[i] = src[i];
			i++;
		}
		free(ptr);
	}
	return ((void *)dst);
}