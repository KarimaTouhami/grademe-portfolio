#include <stddef.h>

int my_memcmp(void *s1, void *s2, size_t n)
{
    unsigned char *p = s1;
    unsigned char *q = s2;

    while (n > 0)
    {
        if (*p != *q)
            return (*p - *q);
        n--;
        p++;
        q++;
    }
    return 0;
}