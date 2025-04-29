#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node *first;
	t_node *second;
	
	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	stack->top = second;
}