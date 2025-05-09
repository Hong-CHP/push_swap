#include "push_swap.h"

void    ft_sort_two(t_stack *stack)
{
    t_node *first;
    t_node *second;

    first = stack->top;
    second = first->next;
    if (*(first->value) > *(second->value))
        sa(stack);
}

void    ft_sort_three(t_stack *stack)
{
    t_node *first;
    t_node *second;
    t_node *third;

    if (!stack || stack->size != 3)
        return ;
    first = stack->top;
    second = first->next;
    third = second->next;
    if (*(first->value) > *(second->value) && *(second->value) < *(third->value) && *(first->value) < *(third->value)) // 1 > 2 && 2 < 3 && 1 < 3 == 2 1 3 
        sa(stack);
    else if (*(first->value) < *(second->value) && *(second->value) > *(third->value) && *(first->value) > *(third->value)) // 1 < 2 && 2 > 3 && 1 > 3 == 2 3 1
        rra(stack);
    else if (*(first->value) > *(second->value) && *(first->value) > *(third->value) && *(second->value) < *(third->value)) // 1 > 2 && 1 > 3 && 2 < 3 == 3 1 2
        ra(stack);
    else if (*(first->value) < *(third->value) && *(first->value) < *(second->value) && *(second->value) > *(third->value)) //1 < 3 && 1 < 2 && 2 > 3 == 1 3 2
    {
        sa(stack);
        ra(stack);
    }
    else if (*(first->value) > *(second->value) && *(second->value) > *(third->value)) 
    {
        sa(stack);
        rra(stack);
    }
}

int *min_tab(t_stack *stack, int *min)
{
    t_node  *cur;
    t_node  *node;
    int arr[3] = {0};
    int i;
    int j;

    i = 0;
    cur = stack->top;
    while (cur && i < 3)
    {
        if (i != 0 && *(cur->value) == *min)
            cur = cur->next;
        *min = *(cur->value);
        node = cur;
        while (node->next)
        {
            j = 0;
            while (j < i && *(node->next->value) != arr[j])
                j++;//j = 1
            if (j == i && *min > *(node->next->value))
                *min = *(node->next->value);
            node = node->next;
        }
        if (i < 3)
        {
            arr[i] = *min;
            i++;
        }
        cur = cur->next;
    }
    i = 0;
    while (i < 3)
    {
        printf("%d, ", arr[i++]);
    }
}

// int find_min_position(t_stack *stack_a, int *min)
// {
//     t_node *cur;
//     int pos;
//     int min_pos;
//     int arr[3];
//     int i;

//     pos = 1;
//     min_pos = pos;
//     cur = stack_a->top;
//     *min = *(stack_a->top->value);
//     i = 0;
//     while(cur->next)
//     {
//         if (*min > *(cur->next->value))
//         {
//             *min = *(cur->next->value);
//             min_pos = pos + 1;
//         }
//         pos++;
//         cur = cur->next;
//     }
//     return (min_pos);
// }

// void    rotate_to_min(t_stack *stack_a, int min_pos, int min)
// {
//     if (min_pos == 2)
//         sa(stack_a);
//     if (stack_a->size % 2 == 0)
//     {
//         if (min_pos <= stack_a->size / 2 + 1)
//         {
//             while (*(stack_a->top->value) != min)
//                 ra(stack_a);
//         }
//         else
//             while (*(stack_a->top->value) != min)
//                 rra(stack_a);
//     }
//     else
//     {
//         if (min_pos <= (stack_a->size + 1) / 2)
//         {
//             while (*(stack_a->top->value) != min)
//                 ra(stack_a);
//         }
//         else
//             while (*(stack_a->top->value) != min)
//                 rra(stack_a);
//     }
// }

// void    ft_sort_ten(t_stack *stack_a, t_stack *stack_b)
// {
//     int min_pos;
//     int min;

//     while (stack_a->size > 3)
//     {
//         min_pos = find_min_position(stack_a, &min);
//         rotate_to_min(stack_a, min_pos, min);
//         pb(stack_a, stack_b);
//     }
//     ft_sort_three(stack_a);
//     while (stack_b->size > 0)
//         pa(stack_b, stack_a);
// }

void    push_swap(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 1)
        return ;
    if (stack_a->size == 2)
        ft_sort_two(stack_a);
    if (stack_a->size == 3)
        ft_sort_three(stack_a);
    if (stack_a->size > 3 && stack_a->size < 10)
    {
        int min;
        min_tab(stack_a, &min);        
    
        //ft_sort_ten(stack_a, stack_b);

    }
}