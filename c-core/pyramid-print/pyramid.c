#include <unistd.h>
#include <stdlib.h>

void     ft_putchar(char c)
{
    write(1, &c, 1);
}

void     print_n_chars(char c, int n)
{
    int		i;

    i = 0;
    while (i < n)
    {
        ft_putchar(c);
        i++;
    }
}

int     main(int argc, char **argv)
{
    int     height;
    int     i;

    if (argc != 2)
    {
        write(1, "wrong number of arguments\n", 26);
        return (0);
    }
    height = atoi(argv[1]);
    if (height <= 0)
        return (0);
    i = 1;
    while (i <= height)
    {
        print_n_chars(' ', height - i);
        print_n_chars('#', 2 * i - 1);
        ft_putchar('\n');
        i++;
    }
    return (0);
}