#include <unistd.h>

void put_str(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void put_nbr(int n)
{
    if (n >= 10)
    {
        put_nbr(n / 10);
    }
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

int custom_atoi(char *str)
{
    int res = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        put_str("wrong number of arguments\n");
        return (0);
    }

    int n = custom_atoi(argv[1]);
    int i = 1;

    while (i <= 9)
    {
        put_nbr(i);
        put_str(" x ");
        put_nbr(n);
        put_str(" = ");
        put_nbr(i * n);
        put_str("\n");
        i++;
    }

    return (0);
}