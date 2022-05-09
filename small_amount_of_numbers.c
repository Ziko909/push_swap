#include "push_swap.h"

void    sort_two_numbers(t_data *data)
{
    if ((*data->head_a)->index > (*data->head_a)->next->index)
        swap(data->head_a, NULL, 1);
}
void    sort_tree_numbers(t_data *data, int bi)
{
    if ((*data->head_a)->index == bi)
        rotate_inside_one_stack(data->head_a, NULL, 1);
    else if ((*data->head_a)->next->index == bi)
        reverse_rotate_inside_one_stack(data->head_a, NULL, 1);
    if ((*data->head_a)->index > (*data->head_a)->next->index)
        swap(data->head_a, NULL, 1);
}

void    sort_four_numbers(t_data *data)
{
    int pos_of_sm;

    pos_of_sm = pos_of_index(*data->head_a, 0);
    if (pos_of_sm == 0)
        push_to_the_other_stack(data->head_a, data->head_b, 'b');
    else if (pos_of_sm == 1)
    {
        swap(data->head_a, NULL, 1);
        push_to_the_other_stack(data->head_a, data->head_b, 'b');
    }
    else if (pos_of_sm == 2)
    {
        rotate_inside_one_stack(data->head_a, NULL, 1);
        swap(data->head_a, NULL, 1);
        push_to_the_other_stack(data->head_a, data->head_b, 'b');
    }
    else if (pos_of_sm == 3)
    {
        reverse_rotate_inside_one_stack(data->head_a, NULL, 1);
        push_to_the_other_stack(data->head_a, data->head_b, 'b');   
    }
    sort_tree_numbers(data, 3);
    push_to_the_other_stack(data->head_b, data->head_a, 'a');
}

void    sort_five_numbers(t_data *data)
{
    int sm;

    sm = 1;
    while (lst_size(*data->head_a) > 3)
    {
        if ((*data->head_a)->index <= sm)
        {
            if ((*data->head_a)->index == 1)
                sm--;
            push_to_the_other_stack(data->head_a, data->head_b, 'b');
        }
        else
        {
            if (pos_of_index(*data->head_a, sm) <= (lst_size(*data->head_a) / 2))
                rotate_inside_one_stack(data->head_a, NULL, 1);
            else
                reverse_rotate_inside_one_stack(data->head_a, NULL, 1);
        }
    }
    if ((*data->head_b)->index < (*data->head_b)->next->index)
        swap(NULL, data->head_b, 1);
    sort_tree_numbers(data, 4);
    push_to_the_other_stack(data->head_b, data->head_a, 'a');
    push_to_the_other_stack(data->head_b, data->head_a, 'a');
}