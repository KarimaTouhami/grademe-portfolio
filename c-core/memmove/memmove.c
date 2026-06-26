#include <stddef.h>

void *memmove(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;

    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    } 
    else {
        d += n;
        s += n;
        while (n--) {
            *--d = *--s;
        }
    }
    return (dest);
}