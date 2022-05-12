/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:07:33 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/12 10:55:56 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct linked_list{
	int					number;
	int					index;
	struct linked_list	*prev;
	struct linked_list	*next;
}t_list;

typedef struct data{
	t_list	**head_a;
	t_list	**head_b;
	t_list	*node;
	int		h_s;
	int		min_range;
	int		max_range;
	int		i;
	char	*str;
	char	**args;
}t_data;

// Used Functions 
// HelpFul Functions
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str, t_data *data);
int		lst_size(t_list *stack);
void	ft_lst_add_back(t_list **head, t_list *node);
void	ft_lst_add_front(t_list **head, t_list *node);
t_list	*lst_last(t_list *stack);
char	**ft_split(char const *s, char c);
int		pos_of_index(t_list *head, int index);
int		ft_2d_len(char **str);

// instructions inside  One Stack
void	swap(t_list **head_a, t_list **head_b, int mode);
void	push_to_the_other_stack(t_list **src, t_list **dest, char mode);
void	rotate_in_one_stack(t_list **head_a, t_list **head_b, int mode);
void	reverse_rotate_in_one_stack(t_list **head_a, t_list **head_b, int mode);

// instructions inside two Stack
void	rotate_inside_two_stacks(t_list **head_a, t_list **head_b);
void	swap_swap(t_list **head_a, t_list **head_b);
void	reverse_rotate_inside_two_stacks(t_list **head_a, t_list **head_b);

// Main Fonctions
t_data  *ft_init(t_data *data, int ac, char **av, int mode);
t_data	*fill_the_stack_a(int ac, t_data *data);
t_data	*indexing_of_stack(t_data *data);

// Parsing Functions
t_data	*get_joined_args(int ac, char **av, t_data *data);
int		ft_isdigit(char c);
int		ft_is_repeat(t_list *tail, int number);

// sorting functions 
// big stacks 
void	fill_the_stack_b(t_data *data);
void	return_sorted_stack_a(t_data *data);
// small  stacks
void	small_amount_of_numbers(t_data *data);
void	sort_two_numbers(t_data *data);
void	sort_tree_numbers(t_data *data, int bi);
void	sort_four_numbers(t_data *data);
void	sort_five_numbers(t_data *data);

// Error Function
void	ft_error(t_data *data);

// Memory Management Functions
void	ft_free(t_data *data);
void	clear_the_stack(t_list **head);

#endif
