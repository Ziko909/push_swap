/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_of_one_stack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:55:17 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/15 13:05:27 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

void	swap(t_list **head_a, t_list **head_b, int mode)
{
	t_list	*tmp;
	t_list	**head;

	head = NULL;
	if (head_a)
	{
		head = head_a;
		if (mode == 1)
			write(1, "sa\n", 3);
	}
	else if (head_b)
	{
		head = head_b;
		if (mode == 1)
			write(1, "sb\n", 3);
	}	
	if (*head && (*head)->next)
	{
		tmp = (*head)->next;
		(*head)->next = tmp->next;
		tmp->next = *head;
		*head = tmp;
	}
}

void	push_to_the_other_stack(t_list **src, t_list **dest, char mode)
{
	t_list	*tmp;

	if (mode == 'a')
		write(1, "pa\n", 3);
	else if (mode == 'b')
		write(1, "pb\n", 3);
	if (*src)
	{
		tmp = (*src);
		(*src) = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	rotate_in_one_stack(t_list **head_a, t_list **head_b, int mode)
{
	t_list	*tmp;
	t_list	**head;

	head = NULL;
	if (head_a)
	{
		head = head_a;
		if (mode == 1)
			write(1, "ra\n", 3);
	}
	else if (head_b)
	{
		head = head_b;
		if (mode == 1)
			write(1, "rb\n", 3);
	}
	if (*head && (*head)->next)
	{
		tmp = *head;
		ft_lst_add_back(head, tmp);
	}
}

void	reverse_rotate_in_one_stack(t_list **head_a, t_list **head_b, int mode)
{
	t_list	*tmp_loop;
	t_list	**head;

	head = NULL;
	if (head_a)
	{
		head = head_a;
		if (mode == 1)
			write(1, "rra\n", 4);
	}
	else if (head_b)
	{
		head = head_b;
		if (mode == 1)
			write(1, "rrb\n", 4);
	}
	if (*head && (*head)->next)
	{
		tmp_loop = *head;
		ft_lst_add_front(head, tmp_loop);
	}
}
