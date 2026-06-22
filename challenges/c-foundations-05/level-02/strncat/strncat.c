#include <stddef.h>

char *strncat(char *dst, char *src, size_t n)
{
    size_t i;
    size_t j;

    i = 0;
    while (dst[i] != '\0')
        i++;
    j = 0;
    while (n > j && src[j] != '\0')
    {
        dst[i + j] = src[j];
        j++;
    }
    dst[i + j] = '\0';
    return (dst);
}   