#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int nbr1;
    int nbr2;
    int temp;

    if (argc != 3)
    {
        printf("\n");
        return (0);
    }
    
    nbr1 = atoi(argv[1]);
    nbr2 = atoi(argv[2]);

    while (nbr2 != 0)
    {
        temp = nbr2;
        nbr2 = nbr1 % nbr2;
        nbr1 = temp;
    }
    
    printf("%d\n", nbr1);
    return (0);
}