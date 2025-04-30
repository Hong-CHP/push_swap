#include "push_swap.h"

void    ft_free_stack(t_stack *stack)
{
    t_node *node;
    t_node *next;

    if (!stack)
        return ;
    node = stack->top;
    while (node)
    {
        next = node->next;
        if (node->value)
            free(node->value);
        free(node);
        node = next;
    }
    stack->top = NULL;
    stack->size = 0;
}

void    ft_push(t_stack *stack, int *value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return ;
    node->value = value;
    node->next = stack->top;
    node->prev = NULL;
    if (stack->top != NULL)
        stack->top->prev = node;
    stack->top = node;
    stack->size++;
}

void    ft_print_stack(t_stack *stack)
{
    t_node *cur;

    cur = stack->top;
    while (cur)
    {
        printf(" <- %d - > ", *(cur->value));
        cur = cur->next;
    }
    printf("NULL\n");
}

void	get_value_init_stack(int argc, char *argv[])
{
    int *value;
    int i;
    t_stack stack_a = {NULL, 0};
    t_stack stack_b = {NULL, 0};

    i = 0;
    while (i < argc)
    {
        value = malloc(sizeof(int));
        if (!value)
            return ;
        *value = ft_atoi(argv[i]);
        ft_push(&stack_a, value);
        i++;
    }
    printf("%d\n", stack_a.size);
    ft_print_stack(&stack_a);
    swap_top_two(&stack_a);
    ft_print_stack(&stack_a);
    printf("-------------------\n");
    push_to_top(&stack_a, &stack_b);
    ft_print_stack(&stack_a);
    ft_print_stack(&stack_b);
    printf("-------------------\n");
    push_to_top(&stack_b, &stack_a);
    ft_print_stack(&stack_a);
    ft_print_stack(&stack_b);
    rotate_to_top(&stack_a);
    ft_print_stack(&stack_a);
    reverse_rotate(&stack_a);
    ft_print_stack(&stack_a);
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
}