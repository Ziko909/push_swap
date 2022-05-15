/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:40:41 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/14 13:19:10 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../bonus/gnl/get_next_line.h"

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
	int		i;
	char	*str;
	char	*in_str;
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
char	**ft_split(char *s, char c);
int		ft_2d_len(char **str);
int		ft_strcmp(char *s1, char *s2);
int		stack_is_sorted(t_list *head);

// instructions inside  One Stack
void	swap(t_list **head_a, t_list **head_b);
void	push_to_the_other_stack(t_list **src, t_list **dest);
void	rotate_in_one_stack(t_list **head_a, t_list **head_b);
void	reverse_rotate_in_one_stack(t_list **head_a, t_list **head_b);

// instructions inside two Stack
void	rotate_inside_two_stacks(t_list **head_a, t_list **head_b);
void	swap_swap(t_list **head_a, t_list **head_b);
void	reverse_rotate_inside_two_stacks(t_list **head_a, t_list **head_b);

// Main Fonctions
t_data	*ft_init(t_data *data, int ac, char **av, int mode);
t_data	*fill_the_stack_a(int ac, t_data *data);
t_data	*indexing_of_stack(t_data *data);

// Parsing Functions
t_data	*get_joined_args(int ac, char **av, t_data *data);
int		ft_isdigit(char c);
int		ft_is_repeat(t_list *tail, int number);

// Error Function
void	ft_error(t_data *data);

// Memory Management Functions
void	ft_free(t_data *data);
void	clear_the_stack(t_list **head);

#endif
