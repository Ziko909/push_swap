/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:37:47 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/15 13:06:09 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

int	lst_size(t_list *stack)
{
	int	i;

	i = 1;
	while (stack && i++)
		stack = stack->next;
	return (i - 1);
}

t_list	*lst_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_lst_add_back(t_list **head, t_list *node)
{
	t_list	*tmp_loop;

	*head = (*head)->next;
	tmp_loop = *head;
	while (tmp_loop->next)
		tmp_loop = tmp_loop->next;
	tmp_loop->next = node;
	node->next = NULL;
}

void	ft_lst_add_front(t_list **head, t_list *node)
{
	t_list	*tmp;

	while (node->next)
	{
		tmp = node;
		node = node->next;
	}
	node->next = *head;
	*head = node;
	tmp->next = NULL;
}

int	pos_of_index(t_list *head, int index)
{
	int	pos;

	pos = 0;
	while (head && head->index != index)
	{
		head = head->next;
		pos++;
	}
	return (pos);
}
