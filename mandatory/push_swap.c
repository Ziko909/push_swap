/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:22:41 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/14 15:16:11 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_data	*fill_the_stack_a(int ac, t_data *data)
{
	t_list	*tmp;

	data->i = 0;
	ft_init(data, 1);
	while (data->args[data->i])
	{
		data->node->next = NULL;
		data->node->number = ft_atoi(data->args[data->i], data);
		if (ft_is_repeat(data->node->prev, data->node->number))
			ft_error(data);
		if (data->i < ac - 1)
		{
			data->node->next = malloc(sizeof(t_list));
			if (!(data->node->next))
				ft_error(data);
			tmp = data->node;
			data->node = data->node->next;
			data->node->prev = tmp;
		}
		data->i++;
	}
	if (stack_is_sorted(*data->head_a))
		exit(0);
	return (data);
}

t_data	*get_joined_args(int ac, char **av, t_data *data)
{
	data->i = 1;
	while (data->i <= ac - 1)
	{
		if (av[data->i][0] == '\0')
		{
			if (data->str)
				free(data->str);
			ft_error(data);
		}
		if (data->i != 1)
			data->str = ft_strjoin(data->str, " ");
		data->str = ft_strjoin(data->str, av[data->i]);
		data->i++;
	}
	data->args = ft_split(data->str, ' ');
	free(data->str);
	return (data);
}

t_data	*indexing_of_stack(t_data *data)
{
	t_list	*tmp_loop;
	t_list	*tmp;
	int		len;
	int		gt;

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

t_data	*ft_init(t_data	*data, int mode)
{
	if (mode == 0)
	{
		data->str = NULL;
		data->args = NULL;
		data->head_a = NULL;
		data->head_b = NULL;
		data->min_range = 1;
	}
	else
	{
		data->head_a = malloc(sizeof(t_list *));
		if (!data->head_a)
			ft_error(data);
		(*data->head_a) = NULL;
		data->head_b = malloc(sizeof(t_list *));
		if (!data->head_b)
			ft_error(data);
		(*data->head_b) = NULL;
		data->node = malloc(sizeof(t_list));
		if (!data->node)
			ft_error(data);
		(*data->head_a) = data->node;
		(*data->head_a)->prev = NULL;
	}
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac >= 2)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			ft_error(data);
		data = ft_init(data, 0);
		data = get_joined_args(ac, av, data);
		data = fill_the_stack_a(ft_2d_len(data->args), data);
		indexing_of_stack(data);
		if (lst_size(*data->head_a) <= 5)
			small_amount_of_numbers(data);
		else
		{
			if (lst_size(*data->head_a) <= 250)
				data->max_range = 15;
			else
				data->max_range = 25;
			fill_the_stack_b(data);
			return_sorted_stack_a(data);
		}
		ft_free(data);
	}
	return (0);
}
