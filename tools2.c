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

int     ft_isdigit(char c)
{
    return(c >= '0' && c <= '9');
}