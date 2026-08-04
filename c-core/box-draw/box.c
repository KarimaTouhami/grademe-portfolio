#include <unistd.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    draw_box(int width, int height)
{
    int     r;
    int     c;

    r = 0;
    while (r < height)
    {
        c = 0;
        while (c < width)
        {
            if ((r == 0 || r == height - 1) && (c == 0 || c == width - 1))
                ft_putchar('+');
            else if (r == 0 || r == height - 1)
                ft_putchar('-');
            else if (c == 0 || c == width - 1)
                ft_putchar('|');
            else
                ft_putchar(' ');
            c++;
        }
        ft_putchar('\n');
        r++;
    }
}

int     main(int argc, char **argv)
{
    int     width;
    int     height;

	if (argc != 3)
    {
        write(1, "wrong number of arguments\n", 26);
		return (0);
    }
    width = atoi(argv[1]);
    height = atoi(argv[2]);
    if (width <= 0 || height <= 0)
        return (0);
    draw_box(width, height);
    return (0);
}