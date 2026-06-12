#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }

    int i = 0;
    char *str = argv[1];

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            char folded = 'z' - (str[i] - 'a');
            write(1, &folded, 1);
        }
        else
        {
			write(1, &str[i], 1);
        }
        i++;
    }

    write(1, "\n", 1);
    return (0);
}