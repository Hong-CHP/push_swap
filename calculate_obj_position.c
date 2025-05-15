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
    
void    find_obj_node_pos(t_stack *stack_a, int *arr, int start, int end, int *pos_obj)
{
    t_node *cur;
    int index;
    int pos;
    int found;

    index = 0;
    printf("start = %d\n", start); 
    printf("end = %d\n", end); 
    while (start < end) //0-4, 4-8
    //0 3 6 7, 12 16 19 22, 
    {
        pos = 1;
        cur = stack_a->top;
        found = 0;
        while (cur) //stack_a = 7 0 3 6, 
        {
            if (arr[start] == *(cur->value)) //arr0
            {
                printf("this show cur->value is: %d\n", *(cur->value));
                pos_from_top_or_bottom(stack_a, pos, pos_obj, index);
                found = 1;
            }
            pos++;
            cur =cur->next;
        }
        if (!found)
            pos_obj[index] = -1; //pos_obj[3] = -1
        start++; //1
        index++;
    }
    printf("pos_obj is: %d %d %d %d\n", pos_obj[0], pos_obj[1], pos_obj[2], pos_obj[3]);
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
