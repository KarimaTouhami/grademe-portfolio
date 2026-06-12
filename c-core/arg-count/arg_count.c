#include <unistd.h>

void put_number(int n)
{
    char digit;

    if (n >= 10)
    {
        put_number(n / 10);
    }
    digit = (n % 10) + '0';
    write(1, &digit, 1);
}

int main(int argc, char **argv)
{
    (void)argv; 
	
	int count = argc - 1;

    put_number(count);
    write(1, "\n", 1);

    return (0);
}