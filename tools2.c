#include "push_swap.h"

int	lst_size(t_list *stack)
{
	int	i;

	i = 1;
	while (stack && i++)
		stack = stack->next;
	return (i - 1);
}

t_list  *lst_last(t_list *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

int pos_of_index(t_list *head, int index)
{
    int pos;

    pos = 0;
    while (head && head->index != index)
    {
        head = head->next;
        pos++;
    }
    return (pos);
}

int ft_is_repeat(t_list *tail, int number)
{
    while (tail)
    {
        if (tail->number == number)
            return (1);
        tail = tail->prev;
    }
    return (0);
}

// void    ft_error(t_data *data)
// {
//     exit(0);
// }

void ft_error(t_data *data)
{
    ft_free(data);
    write(2, "ERROR\n", 6);
    exit(1);
}

int     ft_isdigit(char c)
{
    return(c >= '0' && c <= '9');
}

void    clear_the_stack(t_list **head)
{
    t_list  *tmp;

    while (*head != NULL)
    {
        tmp = *head;
        free(tmp);
        *head = (*head)->next;
    }
}

void    ft_free(t_data *data)
{
     int    i;
     
     i = -1;
    if (data)
    {
        if(data->args)
            while(data->args[++i])
                free(data->args[i]);
        if (data->str)
            free(data->str);
        if (data->head_a)
            clear_the_stack(data->head_a);
        if (data->head_b)
            clear_the_stack(data->head_a);
    }
}
// int closer_to_the_front(t_list *head, int max_range)
// {
//     int pos;
    
//     pos = 0;
//     while (head && head->index > max_range)
//     {
//         head = head->next;
//         pos++;
//     }
//     return (pos);
// }

// int closer_to_the_back(t_list *head, int max_range)
// {
//     int pos;
    
//     pos = 0;
//     while (head && head->index > max_range)
//     {
//         head = head->prev;
//         pos++;
//     }
//     return (pos);
// }

