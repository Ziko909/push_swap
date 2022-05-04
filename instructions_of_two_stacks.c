/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_of_two_stacks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:30:02 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/22 07:22:44 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
void	swap_swap(t_list **head_a, t_list **head_b)
{
	swap(head_a, NULL);
	swap(NULL, head_b);
}

void	rotate_inside_two_stacks(t_list **head_a, t_list **head_b)
{
	rotate_inside_one_stack(head_a, NULL);
	rotate_inside_one_stack(NULL, head_b);
}

void	reverse_rotate_inside_two_stacks(t_list **head_a, t_list **head_b)
{
	reverse_rotate_inside_one_stack(head_a, NULL);
	reverse_rotate_inside_one_stack(NULL, head_b);
}
