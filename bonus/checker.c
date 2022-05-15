/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:46:58 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/14 15:22:48 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap_bonus.h"

void	ft_instructions(t_data *data, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push_to_the_other_stack(data->head_b, data->head_a);
	else if (!ft_strcmp(str, "pb\n"))
		push_to_the_other_stack(data->head_a, data->head_b);
	else if (!ft_strcmp(str, "sa\n"))
		swap(data->head_a, NULL);
	else if (!ft_strcmp(str, "sb\n"))
		swap(NULL, data->head_b);
	else if (!ft_strcmp(str, "ss\n"))
		swap_swap(data->head_a, data->head_b);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_in_one_stack(data->head_a, NULL);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_in_one_stack(NULL, data->head_b);
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate_in_one_stack(data->head_a, NULL);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate_in_one_stack(NULL, data->head_b);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_inside_two_stacks(data->head_a, data->head_b);
	else if (!ft_strcmp(str, "rrr\n"))
		reverse_rotate_inside_two_stacks(data->head_a, data->head_b);
	else
		ft_error(data);
	free(str);
}

t_data	*fill_the_stack_a(int ac, t_data *data)
{
	t_list	*tmp;

	free(data->str);
	data->i = 0;
	ft_init(data, 0, 0, 1);
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
	return (data);
}

t_data	*ft_init(t_data	*data, int ac, char **av, int mode)
{
	if (mode == 0)
	{
		data->str = NULL;
		data->args = NULL;
		data->head_a = NULL;
		data->head_b = NULL;
		data = get_joined_args(ac, av, data);
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
		data = ft_init(data, ac, av, 0);
		data->args = ft_split(data->str, ' ');
		data = fill_the_stack_a(ft_2d_len(data->args), data);
		while (1337)
		{
			data->in_str = get_next_line(0);
			if (!data->in_str)
				break ;
			else
				ft_instructions(data, data->in_str);
		}
		if (stack_is_sorted(*data->head_a) && !(*data->head_b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free(data);
	}
}
