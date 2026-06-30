#include <unistd.h>

#include <unistd.h>

int puts(const char *s) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    if (write(1, s, len) < 0) {
        return -1;
	}

    if (write(1, "\n", 1) < 0) {
        return -1;
	}

    return 0;
}