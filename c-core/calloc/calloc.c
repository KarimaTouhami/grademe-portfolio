#include <stdlib.h>
#include <stdint.h>

void	*calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			total_bytes;
	size_t			i;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	
	total_bytes = nmemb * size;
	
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
		
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_bytes)
	{
		byte_ptr[i] = 0;
		i++;
	}
	
	return (ptr);
}