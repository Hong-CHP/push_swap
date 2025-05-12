#include "push_swap.h"

int *pos_from_top_or_bottom(t_stack *stack_a, int pos, int *pos_obj, int start)
{
    if (stack_a->size % 2 == 0)
    {
        if (pos <= stack_a->size / 2 + 1)
        {
            pos_obj[start] = pos - 1;
        }
        else
            pos_obj[start] = stack_a->size - pos + 1;
    }
    else
    {
        if (pos <= (stack_a->size + 1) / 2)
        {
            pos_obj[start] = pos - 1;
        }
        else
            pos_obj[start] = stack_a->size - pos + 1;
    }
    return (pos_obj);
}
    
int *find_obj_node_pos(t_stack *stack_a, int times, int *arr, int sqrt)
{
    t_node *cur;
    int start;
    int end;
    int *pos_obj;
    int pos;

    pos_obj = (int *)malloc(sizeof(int) * sqrt);
    if (!pos_obj)
        return (NULL);
    start = (times - 1) * sqrt;
    end = times * sqrt;
    while (start < end)
    {
        pos = 1;
        cur = stack_a->top;
        while (cur)
        {
            if (arr[start] == *(cur->value))
                pos_from_top_or_bottom(stack_a, pos, pos_obj, start);
            pos++;
            cur =cur->next;
        }
        start++;
    }
    return (pos_obj);
}

t_obj   find_shorter_path_rotate(t_stack *stack_a, int times, int *arr, int sqrt)
{
    t_obj   obj;
    int *obj_pos;
    int i;
    int shortest;
    int obj_value;

    obj_pos = find_obj_node_pos(stack_a, times, arr, sqrt);
    i = 0;
    printf("arr is : ");
    while (i < sqrt)
        printf("%d ", arr[i++]);
    printf("\n");
    i = 0;
    printf("obj_pos is : ");
    while (i < sqrt)
        printf("%d ", obj_pos[i++]);
    printf("\n");
    i = 1;
    shortest = obj_pos[0];
    while (i < sqrt)
    {
        if (shortest > obj_pos[i])
        {
            shortest = obj_pos[i];
            obj_value = i;
        }
        else
        {
            shortest = obj_pos[0];
            obj_value = 0;
        }
        i++;
    }
    obj.obj_path = shortest;
    obj.obj_value = arr[obj_value];
    return (obj);
}

int get_obj_real_pos(t_stack *stack_a, t_obj *shortest_obj)
{
    t_node *cur;
    int real_pos;

    real_pos = 0;
    cur = stack_a->top;
    while (cur)
    {
        if (*(cur->value) == shortest_obj->obj_value)
            return (real_pos);
        real_pos++;
        cur = cur->next;
    }
    return (-1);
}
