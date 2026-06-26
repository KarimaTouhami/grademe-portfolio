#include <unistd.h>

void put_str(const char *s)
{
    int i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0')
        {
            break;
        }

        if (argv[i][0] != '-' || argv[i][1] == '\0')
        {
            break;
        }

        char flag = argv[i][1];

        if (flag == 'p')
        {
            if (i + 1 < argc)
            {
                put_str("Option p with arg ");
                put_str(argv[i + 1]);
                put_str("\n");
                i += 2;
                continue;
            }
        }
        else if (flag == 'l' || flag == 'c')
        {
            put_str("Option ");
            write(1, &flag, 1);
            put_str("\n");
        }
        
        i++;
    }
    return (0);
}