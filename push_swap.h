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
//void    push_swap(char *str);
void	sa(t_stack *stack);

#endif