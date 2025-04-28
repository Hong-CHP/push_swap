#include "push_swap.h"

int main(int argc, char *argv[])
{
    int i;

    if (argc <= 1)
    {
        write(1, "Error\n", 6);
        exit(1);
    }
    i = 1;
    while(i < argc)
    { 
        push_swap(argv[i]);
        i++;
    }
    return (0);
}