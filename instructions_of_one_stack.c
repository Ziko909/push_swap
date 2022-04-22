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
void	swap(t_list **head)
{
	t_list	*tmp;
	
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

void	rotate_inside_one_stack(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp_loop;
	
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

void	reverse_rotate_inside_one_stack(t_list **head)
{
	t_list	*tmp_loop;
	t_list	*tmp;
	
	if (*head && (*head)->next)
	{
		tmp_loop = *head;
		while (tmp_loop->next)
		{
			if (!tmp_loop->next->next)
				tmp = tmp_loop;
			tmp_loop = tmp_loop->next;
		}
		tmp_loop->next = *head;
		*head = tmp_loop;
		tmp->next = NULL;
	}
}
