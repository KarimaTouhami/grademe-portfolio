#include <unistd.h>
void write_str(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
