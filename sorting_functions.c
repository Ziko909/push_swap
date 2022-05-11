/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:51:06 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/11 17:54:04 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	fill_the_stack_b(t_data *data)
{
	while (lst_size(*data->head_a) > 0)
	{
		if ((*data->head_a)->index <= data->min_range)
		{
			push_to_the_other_stack(data->head_a, data->head_b, 'b');
			if ((*data->head_a) && (*data->head_a)->index > data->max_range + data->min_range)
				rotate_inside_two_stacks(data->head_a, data->head_b);
			else
				rotate_inside_one_stack(NULL, data->head_b, 1);
			data->min_range++;
		}
		else if ((*data->head_a)->index < data->max_range + data->min_range)
		{
			push_to_the_other_stack(data->head_a, data->head_b, 'b');
			data->min_range++;
		}
		else
			rotate_inside_one_stack(data->head_a, NULL, 1);
		if (lst_size(*data->head_b) > 1)
		{
			if ((*data->head_b)->index < (*data->head_b)->next->index)
				swap(NULL, data->head_b, 1);
		}	
	}
}

void	return_sorted_stack_a(t_data *data)
{
	int	bi;

	bi = lst_size(*data->head_b) - 1;
	while (lst_size((*data->head_b)) > 0)
	{
		if ((*data->head_b)->index == bi)
		{
			push_to_the_other_stack(data->head_b, data->head_a, 'a');
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
	if (lst_size(*data->head_a) == 2)
		sort_two_numbers(data);
	if (lst_size(*data->head_a) == 3)
		sort_tree_numbers(data, 2);
	if (lst_size(*data->head_a) == 4)
		sort_four_numbers(data);
	if (lst_size(*data->head_a) == 5)
		sort_five_numbers(data);
}
