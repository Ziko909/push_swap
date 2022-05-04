#include "push_swap.h"
void    sort_tree_numbers(t_list **head)
{
    data->end_a = lst_last(*head);
    if ((*head)->index > data->end_a->index)
        rotate_inside_one_stack(head, NULL);
    if (*head)->index > (*head)->next)
        swap(head, NULL);
}

void    sort_four_numbers(t_data *data)
{
    int pos_of_sm;

    pos_of_sm = pos_of_index(*head);
    if (pos_of_sm == 0)
        push_to_the_other_stack(head, data->head_b);
    else if (pos_of_sm = 1)
    {
        swap(head, NULL);
        push_to_the_other_stack(head, data->head_b);
    }
    else if (pos_of_sm == 2)
    {
        rotate_inside_one_stack(head, NULL);
        swap(head, NULL);
        push_to_the_other_stack(head, data->head_b);
    }
    else if (pos_of_sm == 3)
    {
        reverse_rotate_inside_one_stack(head, NULL);
        push_to_the_other_stack(head, data->head_b);   
    }
    push_to_the_other_stack(data->head_b, head);
}