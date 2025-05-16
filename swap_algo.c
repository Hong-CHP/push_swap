#include "push_swap.h"

t_node  *get_stack_b_bottom(t_stack *stack_b)
{
    t_node *cur;

    if (!stack_b)
        return (NULL);
    cur = stack_b->top;
    while (cur->next)
        cur = cur->next;
    return (cur);
}

void    test_rr_ra_and_rotate(t_stack *stack_a, t_stack *stack_b, t_obj *shortest_obj)
{
    int b_bottom;

    if (stack_b->size > 2)
        b_bottom = *(get_stack_b_bottom(stack_b)->value);
    while (*(stack_a->top->value) != shortest_obj->obj_value)
    {
        if (stack_b->size > 2 && *(stack_b->top->value) < b_bottom)
            rr(stack_a, stack_b);
        else
            ra(stack_a);
    }
}

void    test_rrr_rra_and_rotate(t_stack *stack_a, t_stack *stack_b, t_obj *shortest_obj)
{
    int b_bottom;

    if (stack_b->size > 2)
        b_bottom = *(get_stack_b_bottom(stack_b)->value);
    while (*(stack_a->top->value) != shortest_obj->obj_value)
    {
        if (stack_b->size > 2 && *(stack_b->top->value) < b_bottom)
            rrr(stack_a, stack_b);
        else
            rra(stack_a);
    }
}

void    swap_and_rotate(t_stack *stack_a, t_stack *stack_b, t_obj *shortest_obj, int real_pos)
{

    if (real_pos == 2)
    {
        if (stack_b->size >= 2 && *(stack_b->top->value) < *(stack_b->top->next->value))
            ss(stack_a, stack_b);
        else
            sa(stack_a);
    }
    if (stack_a->size % 2 == 0)
    {
        if (real_pos <= stack_a->size / 2 + 1)
            test_rr_ra_and_rotate(stack_a, stack_b, shortest_obj);
        else
            test_rrr_rra_and_rotate(stack_a, stack_b, shortest_obj);
    }
    else
    {
        if (real_pos <= (stack_a->size + 1) / 2)
            test_rr_ra_and_rotate(stack_a, stack_b, shortest_obj);
        else
            test_rrr_rra_and_rotate(stack_a, stack_b, shortest_obj);
    }
}

void    rotate_obj_to_top(t_stack *stack_a, t_stack *stack_b, t_obj *shortest_obj)
{
    int real_pos;
    int b_bottom;

    real_pos = get_obj_real_pos(stack_a, shortest_obj);
    swap_and_rotate(stack_a, stack_b, shortest_obj, real_pos);
    pb(stack_a, stack_b);
    if (stack_b->size > 2)
        b_bottom = *(get_stack_b_bottom(stack_b)->value);
    if (stack_b->size >= 2 && *(stack_b->top->value) < *(stack_b->top->next->value) && *(stack_b->top->value) > b_bottom)
        sb(stack_b);
    if (stack_b->size >= 2 && *(stack_b->top->value) < *(stack_b->top->next->value) && *(stack_b->top->value) < b_bottom)
        rb(stack_b);
}
//./a.out 12 28 54 23 6 41 3 19 22 0 30 7 52 16 49 38 25 53

void push_swap_algo(t_stack *stack_a, t_stack *stack_b, int sqrt, int *arr)
{
    int times;
    t_obj shortest_obj;
    int *pos_obj;
    int i;
    int start;

    i = 0;
    while (i < sqrt - 1)
    {
        times = i * sqrt;
        pos_obj = (int *)malloc(sizeof(int) * sqrt);
        if (!pos_obj)
            return ;
        ft_bzero(pos_obj, sqrt);
        start = times;
        while (times < sqrt * i + sqrt)
        {
            find_obj_node_pos(stack_a, arr, start, sqrt * i + sqrt, pos_obj);
            shortest_obj = find_shorter_path_rotate(arr, sqrt, pos_obj, start);
            rotate_obj_to_top(stack_a, stack_b, &shortest_obj);
            times++;
        }
        free(pos_obj);     
        i++;
    }
}
