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
    return (pos_obj); //0-9, 3-8, 4 -4
}
    
void    find_obj_node_pos(t_stack *stack_a, int *arr, int sqrt, int *pos_obj)
{
    t_node *cur;
    int start;
    int pos;
    int found;

    start = 0;
    while (start < sqrt) //0 1 2
    {  //0 3 4 7
        pos = 1;
        cur = stack_a->top;
        found = 0;
        while (cur) //stack_a = 3 0 4
        {
            if (arr[start] == *(cur->value)) //arr[0], arr[1], arr[2], arr[3] not found
            {
                pos_from_top_or_bottom(stack_a, pos, pos_obj, start);
                found = 1;
            }
            pos++;
            cur =cur->next;
        }
        if (!found)
            pos_obj[start] = -1; //pos_obj[3] = -1
        start++; //1 2 3 4
    }
}

t_obj   find_shorter_path_rotate(int *arr, int sqrt, int *pos_obj)
{
    t_obj   obj;
    int i;
    int shortest;
    int obj_value;

    i = 0;
    while(i < sqrt && pos_obj[i] == -1)
        i++;
    shortest = pos_obj[i]; //shortest = obj[1] = 1
    obj_value = i;
    while (i < sqrt)
    {
        if (pos_obj[i] != -1)
        {
            if (shortest > pos_obj[i])
            {
                shortest = pos_obj[i];
                obj_value = i;
            }
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

    if (shortest_obj->obj_path == -1)
        return (-1);
    real_pos = 1;
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
