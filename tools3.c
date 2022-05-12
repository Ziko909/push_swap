/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:29:43 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/12 10:51:45 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_2d_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(t_data *data)
{
	ft_free(data);
	write(2, "ERROR\n", 6);
	exit(1);
}

void	clear_the_stack(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		free(tmp);
		*head = (*head)->next;
	}
	free(head);
}

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	if (data)
	{
		if (data->args)
		{
			while (data->args[++i])
				free(data->args[i]);
			free(data->args);
		}
		if (data->str)
			free(data->str);
		if (data->head_a)
			clear_the_stack(data->head_a);
		if (data->head_b)
			clear_the_stack(data->head_b);
		free(data);
	}
}

int	ft_is_repeat(t_list *tail, int number)
{
	while (tail)
	{
		if (tail->number == number)
			return (1);
		tail = tail->prev;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
