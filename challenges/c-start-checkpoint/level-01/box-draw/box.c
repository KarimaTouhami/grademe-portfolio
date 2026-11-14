
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int w, h, x, y;
    char c;

    if (argc != 3)
        return (write(1, "wrong number of arguments\n", 26), 0);
    w = atoi(argv[1]);
    h = atoi(argv[2]);

    if (w <= 0 || h <= 0)
        return (0);
    y = 0;
    while (y < h)
    {
        x = 0;
        while (x < w)
        {
            if ((y == 0 || y == h - 1) && (x == 0 || x == w - 1))
                c = '+';
            else if (y == 0 || y == h - 1)
                c = '-';
            else if (x == 0 || x == w - 1)
                c = '|';
            else
                c = ' ';
            write(1, &c, 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
    return (0);
}
