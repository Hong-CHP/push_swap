#include "push_swap.h"

void    swap_and_rotate(t_stack *stack_a, t_obj *shortest_obj, int real_pos)
{
    if (real_pos == 2)
        sa(stack_a);
    if (stack_a->size % 2 == 0)
    {
        if (real_pos <= stack_a->size / 2 + 1)
        {
            while (*(stack_a->top->value) != shortest_obj->obj_value)
                ra(stack_a);
        }
        else
            while (*(stack_a->top->value) != shortest_obj->obj_value)
                rra(stack_a);
    }
    else
    {
        if (real_pos <= (stack_a->size + 1) / 2)
        {
            while (*(stack_a->top->value) != shortest_obj->obj_value)
                ra(stack_a);
        }
        else
            while (*(stack_a->top->value) != shortest_obj->obj_value)
                rra(stack_a);
    }
}

void    rotate_obj_to_top(t_stack *stack_a, t_obj *shortest_obj)
{
    int real_pos;

    printf("shortest_obj.obj_path is : %d\n", shortest_obj->obj_path);
    printf("shortest_obj.obj_value is : %d\n", shortest_obj->obj_value);
    real_pos = get_obj_real_pos(stack_a, shortest_obj);
    printf("real position of obj is : %d\n", real_pos);
    swap_and_rotate(stack_a, shortest_obj, real_pos);
}

void push_swap_algo(t_stack *stack_a, t_stack *stack_b)
{
    int sqrt;
    int arr[stack_a->size];
    int times;
    t_obj shortest_obj;
    int *pos_obj;

    sqrt = 0;
    get_sort_arr_preparation_for_algo(stack_a, &sqrt, arr);
    pos_obj = (int *)malloc(sizeof(int) * sqrt);
    if (!pos_obj)
        return ;
    times = 0;
    while (times < sqrt) // 0 < 4, 1 <4
    {
        find_obj_node_pos(stack_a, arr, sqrt, pos_obj);
        shortest_obj = find_shorter_path_rotate(arr, sqrt, pos_obj); // 7 - 1
        rotate_obj_to_top(stack_a, &shortest_obj); 
        pb(stack_a, stack_b);
        times++; // 1
    }
}