#include <stddef.h>

int     strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
        {
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
        if (s1[i] == '\0')
        {
            break;
        }
        i++;
    }
    return (0);
}