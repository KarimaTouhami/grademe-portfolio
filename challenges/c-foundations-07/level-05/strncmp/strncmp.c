#include <stddef.h>

int strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;

	while (i < n) {
        int diff = (unsigned char)s1[i] - (unsigned char)s2[i];
        if (diff != 0 || s1[i] == '\0')
            return (diff);
		i++;
    }
    return (0);
}
