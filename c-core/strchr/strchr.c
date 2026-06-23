#include <stddef.h>

char *strchr(const char *s, int c)
{
    char target = (char)c;

    while (*s != '\0')
    {
        if (*s == target)
        {
            return ((char *)s);
        }
        s++; 
    }

    if (*s == target)
    {
        return ((char *)s);
    }

    return (NULL);
}