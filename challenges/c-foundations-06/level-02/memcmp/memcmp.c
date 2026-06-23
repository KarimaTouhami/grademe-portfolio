#include <stddef.h>

int memcmp(const void *b, const void *c, size_t n)
{
    const unsigned char *p = b;
    const unsigned char *q = c;

    while (n > 0)
    {
        if (*p != *q)
            return (*p - *q);
        n--;
        p++;
        q++;
    }
    return (0);
}
