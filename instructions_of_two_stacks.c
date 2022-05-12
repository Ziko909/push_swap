/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_of_two_stacks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:30:02 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/11 19:35:03 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_swap(t_list **head_a, t_list **head_b)
{
	write(1, "ss\n", 3);
	swap(head_a, NULL, 2);
	swap(NULL, head_b, 2);
}

void	rotate_inside_two_stacks(t_list **head_a, t_list **head_b)
{
	rotate_in_one_stack(head_a, NULL, 2);
	write(1, "rr\n", 3);
	rotate_in_one_stack(NULL, head_b, 2);
}

void	reverse_rotate_inside_two_stacks(t_list **head_a, t_list **head_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate_in_one_stack(head_a, NULL, 2);
	reverse_rotate_in_one_stack(NULL, head_b, 2);
}
