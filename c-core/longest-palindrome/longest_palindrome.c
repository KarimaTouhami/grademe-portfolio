#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

int get_len(char *str) {
    int len = 0;
    while (str[len]) {
        len++;
    }
    return (len);
}

int is_palindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return (1);
}

void find_and_print_palindrome(char *str) {
    int len = get_len(str);

    if (len == 0) {
        ft_putchar('\n');
        return;
    }

    int max_len = 0;
    int best_start = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (is_palindrome(str, i, j)) {
                int current_len = j - i + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                    best_start = i;
                }
            }
        }
    }

    for (int i = best_start; i < best_start + max_len; i++) {
        ft_putchar(str[i]);
    }
    ft_putchar('\n');
}

int main(int argc, char **argv) {
	char *error = "wrong number of arguments\n";
    int i = 0;
    if (argc != 2) {
        while (error[i]) {
            ft_putchar(error[i]);
			i++;
        }
        return (0);
    }

    find_and_print_palindrome(argv[1]);
    return (0);
}