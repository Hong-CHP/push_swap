#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
    int         *value;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

typedef struct s_stack
{
    t_node *top;
    int     size;
}               t_stack;

int	is_validate_param(char *str);
int ft_atoi(char *str);
void	get_value_init_stack(int argc, char *argv[]);
void	swap_top_two(t_stack *stack);
void	push_to_top(t_stack *stack_a, t_stack *stack_b);
void	rotate_to_top(t_stack *stack);
void    reverse_rotate(t_stack *stack);
void    push_swap(t_stack *stack_a, t_stack *stack_b);
void    push_swap_algo(t_stack *stack_a, t_stack *stack_b);
void    sa(t_stack *stack_a);
void    ra(t_stack *stack_a);
void    rra(t_stack *stack_a);
void    pb(t_stack *stack_b, t_stack *stack_a);
void    pa(t_stack *stack_b, t_stack *stack_a);

#endif