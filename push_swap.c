/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:22:41 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/22 07:21:08 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_data	*fill_the_stack_a(int ac, t_data *data)
{
	t_list	*node;
	t_list	*tmp;

	data->head_a = malloc(sizeof(t_list *));
	data->head_b = malloc(sizeof(t_list *));
	node = malloc(sizeof(t_list));
	(*data->head_a) = node;
	(*data->head_a)->prev = NULL;
	(*data->head_b) = NULL;
	data->i = 0;
	while (data->args[data->i])
	{
		node->number = ft_atoi(data->args[data->i]);
		if (data->i < ac - 2)
		{
			node->next = malloc(sizeof(t_list));
			tmp = node;
			node = node->next;
			node->prev = tmp;
		}
		data->i++;
	}
	node->next = NULL;
	return (data);
}

void print_stack(t_list *head)
{
	while (head)
	{
		printf("in[%d] num[%d]\n",head->index, head->number);
		head = head->next;
	}
}

t_data	*get_joined_args(int ac, char **av, t_data *data)
{
	data->i = 1;
	data->str = NULL;
	while (data->i <= ac - 1)
	{
		if (data->i != 1)
			data->str = ft_strjoin(data->str, " ");
		data->str = ft_strjoin(data->str, av[data->i]);
		data->i++;
	}
	return (data);
}
void	fill_the_stack_b(t_data *data)
{
	while (lst_size(*data->head_a) > 0)
	{
		data->end_a = lst_last((*data->head_a));
		data->end_b = lst_last((*data->head_b));
		if ((*data->head_a)->index <= data->max_range)
		{
			push_to_the_other_stack(data->head_a, data->head_b, 'a');
			data->min_range++;
			data->max_range++;
		}
		else if ((*data->head_a)->index > data->max_range)
		{
			if (lst_size(*data->head_b) >= 2 && data->end_b->index < (*data->head_b)->index)
				rotate_inside_two_stacks(data->head_a, data->head_b);
			else
				rotate_inside_one_stack(data->head_a, NULL, 1);
			write(1, "a\n", 1);
		}
        if (lst_size(*data->head_b) >= 2 && (*data->head_b)->index < (*data->head_b)->next->index)
           swap(NULL, data->head_b, 1);
	}
}

t_data	*indexing_of_stack(t_data *data)
{
	t_list	*tmp_loop;
	t_list	*tmp;
	int	len;
	int	gt;

	len = lst_size((*data->head_a)) - 1;

	tmp_loop = (*data->head_a);
	tmp = (*data->head_a);
	while (tmp)
	{
		gt = 0;
		while (tmp_loop)
		{
			if (tmp->number < tmp_loop->number)
				gt++;
			tmp_loop = tmp_loop->next;	
		}
		tmp->index = len - gt;
		tmp_loop = (*data->head_a);
		tmp = tmp->next;
	}
	return (data);
}

void    return_sorted_stack_a(t_data *data)
{
  int   bi;

  bi = lst_size(*data->head_b) - 1;
  while (lst_size((*data->head_b)) > 0)
  {
	
    if ((*data->head_b)->index == bi)
    {
			push_to_the_other_stack(data->head_b, data->head_a, 'b');
            bi--;
    }
	else
	{
		if (pos_of_index(*data->head_b, bi) <= (lst_size(*data->head_b) / 2))
			rotate_inside_one_stack(NULL, data->head_b, 1);
		else
			reverse_rotate_inside_one_stack(NULL, data->head_b, 1);
	}
  }
}

void	small_amount_of_numbers(t_data *data)
{
	if (lst_size(*data->head_a) == 3)
		sort_tree_numbers(data, 2);
	if (lst_size(*data->head_a) == 4)
		sort_four_numbers(data);
	if (lst_size(*data->head_a) == 5)
		sort_five_numbers(data);
}
int main(int ac, char **av)
{
	t_data	*data;
	if (ac >= 2)
	{
		data = malloc(sizeof(t_data));
		data->min_range = 0;
		data = get_joined_args(ac, av, data);
		data->args = ft_split(data->str, ' ');
		data = fill_the_stack_a(ac, data);
		indexing_of_stack(data);
		if (lst_size(*data->head_a) <= 5)
			small_amount_of_numbers(data);
		else
		{
			if (lst_size(*data->head_a) <= 120)
				data->max_range = 10;
			else if (lst_size(*data->head_b) <= 600)
				data->max_range = 19;
			fill_the_stack_b(data);
			return_sorted_stack_a(data);
		}
	}
}
