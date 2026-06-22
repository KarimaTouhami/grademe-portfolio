#include <stddef.h>

size_t strcspn(const char *s, const char *reject)
{
    size_t i;
    size_t j;

    i = 0;
    while (s[i] != '\0')
    {
        j = 0;
        while (reject[j] != '\0')
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}   