#include "push_swap.h"

int find_sqrt(t_stack *stack_a, int *sqrt)
{
    int size;

    size = stack_a->size;
    while (*sqrt < size / 2)
    {
        if (*sqrt * *sqrt == size)
            return (*sqrt);
        else if (*sqrt * *sqrt > size && (*sqrt - 1) * (*sqrt - 1) < size)
            return (*sqrt - 1);
        (*sqrt)++;
    }
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

void    get_sort_arr_preparation_for_algo(t_stack *stack_a, int *sqrt, int *arr)
{
    int temp;
    int i;
    int j;

    *sqrt = find_sqrt(stack_a, sqrt);
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