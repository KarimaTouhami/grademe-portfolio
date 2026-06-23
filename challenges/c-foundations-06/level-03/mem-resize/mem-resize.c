#include <stdlib.h>
#include <stddef.h>

void *mem_resize(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL)
    {
        return (NULL);
    }

    if (ptr != NULL)
    {
        size_t copy_limit = old_size;
        if (new_size < old_size)
        {
            copy_limit = new_size;
        }

        unsigned char *src = (unsigned char *)ptr;
        unsigned char *dst = (unsigned char *)new_ptr;
        size_t i = 0;
        while (i < copy_limit)
        {
            dst[i] = src[i];
            i++;
        }

        free(ptr);
    }

    return (new_ptr);
}