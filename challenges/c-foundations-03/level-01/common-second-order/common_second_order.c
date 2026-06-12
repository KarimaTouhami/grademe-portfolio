#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }

    char *s1 = argv[1];
    char *s2 = argv[2];
    
    int printed[256] = {0};
    int i;
    int j;
    int found;

    i = 0;
    while (s2[i] != '\0')
    {
        unsigned char c = (unsigned char)s2[i];

        if (printed[c] == 0)
        {
            found = 0;
            j = 0;
            
            while (s1[j] != '\0')
            {
                if (s1[j] == s2[i])
                {
                    found = 1;
                    break;
                }
                j++;
            }

            if (found == 1)
            {
                write(1, &s2[i], 1);
                printed[c] = 1;
            }
        }
        i++;
    }

    write(1, "\n", 1);
    return (0);
}