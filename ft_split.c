#include "push_swap.h"

int is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    else
        return (0);
}

int ft_split_needed(int ac, char *av[])
{
    int i;
    int j;

    i = 0;
    while (i < ac)
    {
        j = 0;
        while (j < ft_strlen(av[i]))
        {
            if (is_space(av[i][j]))
                return (i);
            j++;
        }    
        i++;
    }
    return (0);
}

// char **ft_split(char *str)
// {
    
// }
