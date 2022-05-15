/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_of_two_stack_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:33:21 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/14 08:38:16 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap_bonus.h"

void	swap_swap(t_list **head_a, t_list **head_b)
{
	swap(head_a, NULL);
	swap(NULL, head_b);
}

void	rotate_inside_two_stacks(t_list **head_a, t_list **head_b)
{
	rotate_in_one_stack(head_a, NULL);
	rotate_in_one_stack(NULL, head_b);
}

void	reverse_rotate_inside_two_stacks(t_list **head_a, t_list **head_b)
{
	reverse_rotate_in_one_stack(head_a, NULL);
	reverse_rotate_in_one_stack(NULL, head_b);
}
