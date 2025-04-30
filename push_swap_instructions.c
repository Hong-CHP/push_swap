#include "push_swap.h"

void    sa(t_stack *stack_a)
{
    swap_top_two(stack_a);
}

void    sb(t_stack *stack_b)
{
    swap_top_two(stack_b);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap_top_two(stack_a);
    swap_top_two(stack_b);
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    push_to_top(stack_a, stack_b);
}

void    pb(t_stack *stack_b, t_stack *stack_a)
{
    push_to_top(stack_b, stack_a);
}

void    ra(t_stack *stack_a)
{
    rotate_to_top(stack_a);
}

void    rb(t_stack *stack_b)
{
    rotate_to_top(stack_b);
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate_to_top(stack_a);
    rotate_to_top(stack_b);
}

void    rra(t_stack *stack_a)
{
    reverse_rotate(stack_a);
}

void    rrb(t_stack *stack_b)
{
    reverse_rotate(stack_b);
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}