#include "push_swap.h"

int find_sqrt(t_stack *stack_a)
{
    int size;
    int sqrt;

    sqrt = 0;
    size = stack_a->size;
    while (sqrt * sqrt <= size)
    {
        if (sqrt * sqrt == size)
            return (sqrt);
        sqrt++;
    }
    if (sqrt * sqrt > size && (sqrt - 1) * (sqrt - 1) < size)
        return (sqrt - 1);
    else
        return (0);
}

int *creat_array_from_stack(t_stack *stack_a, int *arr)
{
    t_node *cur;
    int i;

    cur = stack_a->top;
    i = 0;
    while (cur)
    {
        arr[i++] = *(cur->value);
        cur = cur->next;
    }
    return (arr);
}

void    get_sort_arr_preparation_for_algo(t_stack *stack_a, int *arr)
{
    int temp;
    int i;
    int j;

    arr = creat_array_from_stack(stack_a, arr);
    i = 0;
    while (i < stack_a->size - 1)
    {
        j = i + 1;
        while (j < stack_a->size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
}