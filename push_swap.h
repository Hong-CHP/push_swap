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

typedef struct s_obj
{
    int obj_path;
    int obj_value;
}               t_obj;

int	ft_strlen(char *str);
int is_space(char c);
int ft_split_needed(int ac, char *av[]);
char **ft_split(char *str);
int	is_validate_param(char *str);
int	*ft_bzero(int *s, size_t n);
int ft_atoi(char *str);
void    ft_sort_two(t_stack *stack);
void    ft_sort_three(t_stack *stack);
t_obj   find_min_position(t_stack *stack_a);
void    ft_print_stack(t_stack *stack);
int find_sqrt(t_stack *stack_a);
void	get_value_init_stack(int argc, char *argv[]);
void	swap_top_two(t_stack *stack);
void	push_to_top(t_stack *stack_a, t_stack *stack_b);
void	rotate_to_top(t_stack *stack);
void    reverse_rotate(t_stack *stack);
void    push_swap(t_stack *stack_a, t_stack *stack_b);
void push_swap_algo(t_stack *stack_a, t_stack *stack_b, int sqrt, int *arr);
void    get_sort_arr_preparation_for_algo(t_stack *stack_a, int *arr);
void    find_obj_node_pos(t_stack *stack_a, int *arr, int start, int end, int *pos_obj);
t_obj   find_shorter_path_rotate(int *arr, int sqrt, int *pos_obj, int start);
int get_obj_real_pos(t_stack *stack_a, t_obj *shortest_obj);
void    rotate_obj_to_top(t_stack *stack_a, t_stack *stack_b, t_obj *shortest_obj);
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_b, t_stack *stack_a);
void    pa(t_stack *stack_b, t_stack *stack_a);
void    back_to_a(t_stack *stack_a, t_stack *stack_b);

#endif