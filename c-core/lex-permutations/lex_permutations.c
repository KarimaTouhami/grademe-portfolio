#include <unistd.h>
#include <stdlib.h>

int get_len(const char *str) {
    const char *s = str;
    while (*s) {
        s++;
    }
    return (s - str);
}

void sort_string(char *str, int len) {
    int i = 0;
    while (i < len - 1) {
        int j = 0;
        while (j < len - i - 1) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void permute(char *str, int len, int index) {
    if (index == len) {
        write(1, str, len);
        write(1, "\n", 1);
        return;
    }

    int i = index;
    while (i < len) {
        char temp = str[i];
        int j = i;
        while (j > index) {
            str[j] = str[j - 1];
            j--;
        }
        str[index] = temp;

        permute(str, len, index + 1);

        temp = str[index];
        j = index;
        while (j < i) {
            str[j] = str[j + 1];
            j++;
        }
        str[i] = temp;
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return (1);
    }

    int len = get_len(argv[1]);
    if (len == 0) {
        write(1, "\n", 1);
        return (0);
    }

    char *str = malloc(sizeof(char) * (len + 1));
    if (!str) {
        return (0);
    }

    int i = 0;
    while (i < len) {
        str[i] = argv[1][i];
        i++;
    }
    str[len] = '\0';

    sort_string(str, len);
    permute(str, len, 0);

    free(str);
    return (0);
}