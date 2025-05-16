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

t_obj find_min_position(t_stack *stack_a)
{
    t_node *cur;
    int pos;
    int min_pos;
    int min;
    t_obj shortest_obj;

    pos = 0;
    min_pos = pos;
    cur = stack_a->top;
    min = *(stack_a->top->value);
    while(cur->next)
    {
        if (min > *(cur->next->value))
        {
            min = *(cur->next->value);
            min_pos = pos + 1;
        }
        pos++;
        cur = cur->next;
    }
    shortest_obj.obj_path = min_pos;
    shortest_obj.obj_value = min;
    return (shortest_obj);
}

void    push_swap(t_stack *stack_a, t_stack *stack_b)
{
    t_obj shortest_obj;
    int sqrt;
    int arr[stack_a->size];

    if (stack_a->size <= 1)
        return ;
    while (stack_a->size > 5)
    {
        sqrt = find_sqrt(stack_a);
        get_sort_arr_preparation_for_algo(stack_a, arr);
        push_swap_algo(stack_a, stack_b, sqrt, arr);
    }
    if (stack_a->size == 2)
        ft_sort_two(stack_a);
    else if (stack_a->size == 3)
        ft_sort_three(stack_a);
    else if (stack_a->size > 3 && stack_a->size <=5)
    {
        while (stack_a->size > 3)
        {
            shortest_obj = find_min_position(stack_a);
            rotate_obj_to_top(stack_a, stack_b, &shortest_obj);
        }
        ft_sort_three(stack_a);
    }
}

void    back_to_a(t_stack *stack_a, t_stack *stack_b)
{
    while(stack_b->top->next)
    {
        if (*(stack_b->top->value) < *(stack_b->top->next->value))
        {
            if (*(stack_b->top->value) < *(stack_b->top->next->value) && *(stack_b->top->value) < *(stack_b->top->next->next->value))
            {
                pa(stack_b, stack_a);
                sb(stack_b);
                pb(stack_a, stack_b);
            }
            sb(stack_b);
        }
        pa(stack_b, stack_a);
    }
    pa(stack_b, stack_a);
}