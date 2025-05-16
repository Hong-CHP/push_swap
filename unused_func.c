
// int *min_tab(t_stack *stack, int *min)
// {
//     t_node  *cur;
//     t_node  *node;
//     int arr[3] = {0};
//     int i;
//     int j;

//     i = 0;
//     cur = stack->top;
//     while (cur && i < 3)
//     {
//         if (i != 0 && *(cur->value) == *min)
//             cur = cur->next;
//         *min = *(cur->value);
//         node = cur;
//         while (node->next)
//         {
//             j = 0;
//             while (j < i && *(node->next->value) != arr[j])
//                 j++;//j = 1
//             if (j == i && *min > *(node->next->value))
//                 *min = *(node->next->value);
//             node = node->next;
//         }
//         if (i < 3)
//         {
//             arr[i] = *min;
//             i++;
//         }
//         cur = cur->next;
//     }
//     i = 0;
//     while (i < 3)
//     {
//         printf("%d, ", arr[i++]);
//     }
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