/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_of_one_stack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:55:17 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/22 07:22:31 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"
void	swap(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	t_list	**head;

	if (head_a)
	{
		head = head_a;
		write(1, "sa\n", 3);
	}
	else if (head_b)
	{
		head = head_b;
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

void	push_to_the_other_stack(t_list **src, t_list **dest)
{
	write(1, "push\n", 5);
	t_list	*tmp;
	
	if (*src)
	{
		tmp = (*src);
		(*src) = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	rotate_inside_one_stack(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	t_list	*tmp_loop;
	t_list	**head;
	
	if (head_a)
	{
		head = head_a;
		write(1, "ra\n", 3);
	}
	else if (head_b)
	{
		head = head_b;
		write(1, "rb\n", 3);
	}
	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp_loop = *head;
		while (tmp_loop->next)
			tmp_loop = tmp_loop->next;
		tmp_loop->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate_inside_one_stack(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_loop;
	t_list	*tmp;
	t_list	**head;
	
	if (head_a)
	{
		head = head_a;
		write(1, "rra\n", 4);
	}
	else if (head_b)
	{
		head = head_b;
		write(1, "rrb\n", 4);
	}
	if (*head && (*head)->next)
	{
		tmp_loop = *head;
		while (tmp_loop->next)
		{
			tmp = tmp_loop;
			tmp_loop = tmp_loop->next;
		}
		tmp_loop->next = *head;
		*head = tmp_loop;
		tmp->next = NULL;
	}
}
