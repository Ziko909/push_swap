/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_of_one_stack_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:30:51 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/14 14:51:16 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap_bonus.h"

void	swap(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	t_list	**head;

	head = NULL;
	if (head_a)
		head = head_a;
	else if (head_b)
		head = head_b;
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
	t_list	*tmp;

	if (*src)
	{
		tmp = (*src);
		(*src) = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	rotate_in_one_stack(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	t_list	**head;

	head = NULL;
	if (head_a)
		head = head_a;
	else if (head_b)
		head = head_b;
	if (*head && (*head)->next)
	{
		tmp = *head;
		ft_lst_add_back(head, tmp);
	}
}

void	reverse_rotate_in_one_stack(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_loop;
	t_list	**head;

	head = NULL;
	if (head_a)
		head = head_a;
	else if (head_b)
		head = head_b;
	if (*head && (*head)->next)
	{
		tmp_loop = *head;
		ft_lst_add_front(head, tmp_loop);
	}
}
