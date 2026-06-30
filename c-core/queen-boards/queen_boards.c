#include <unistd.h>
#include <stdlib.h>

int safe_spot(int *board, int col, int row) {
    int i = 0;
    while (i < col) {
        if (board[i] == row) {
            return (0);
        }
        int row_diff = board[i] - row;
        int col_diff = i - col;
        if (row_diff == col_diff || row_diff == -col_diff) {
            return (0);
        }
        i++;
    }
    return (1);
}

void ft_putnbr(int n) {
    if (n >= 10) {
        ft_putnbr(n / 10);
    }
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

void solve(int *board, int n, int col) {
    if (col == n) {
        int i = 0;
        while (i < n) {
            ft_putnbr(board[i]);
            if (i < n - 1) {
                write(1, " ", 1);
            }
            i++;
        }
        write(1, "\n", 1);
        return;
    }

    int row = 0;
    while (row < n) {
        if (safe_spot(board, col, row)) {
            board[col] = row;
            solve(board, n, col + 1);
        }
        row++;
    }
}

int ft_atoi(const char *str) {
    int res = 0;
    int i = 0;
    while (str[i] >= '0' && (str[i] <= '9')) {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return (1);
    }

    int n = ft_atoi(argv[1]);

    if (n == 0) {
        write(1, "\n", 1);
        return (0);
    }

    int *board = malloc(sizeof(int) * n);
    if (!board) {
        return (0);
    }

    solve(board, n, 0);

    free(board);
    return (0);
}