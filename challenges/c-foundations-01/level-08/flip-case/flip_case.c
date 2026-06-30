#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "wrong number of arguments\n", 26);
        return 0;
    }

    char *str = argv[1];
    int i = 0;

    while (str[i] != '\0') {
        char c = str[i];

        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        else if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }

        write(1, &c, 1);
        i++;
    }

    write(1, "\n", 1);

    return 0;
}