/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:07:33 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/22 03:35:12 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <libc.h>

typedef struct linked_list{
    int number;
    int index;
    struct linked_list *next;
}t_list;

typedef struct data{
    t_list **head_a;
    t_list **head_b;
    int     min_range;
    int     max_range;
    int     i;
    char    *str;
    char    **args;
}t_data;

// Used Functions 
// HelpFul Functions
char    *ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
int     ft_atoi(const char *str);
int     lst_size(t_list *stack);
t_list  *lst_last(t_list *stack);
char	**ft_split(char const *s, char c);

// instructions inside  One Stack
void    swap(t_list **head);
void	push_to_the_other_stack(t_list **src, t_list **dest);
void	rotate_inside_one_stack(t_list **head);
void	reverse_rotate_inside_one_stack(t_list **head);

// instructions inside two Stack
void	rotate_inside_two_stacks(t_list **head_a, t_list **head_b);
void	swap_swap(t_list **head_a, t_list **head_b);
void    reverse_rotate_inside_two_stacks(t_list **head_a, t_list **head_b);

// Main Fonctions
t_data	*fill_the_stack_a(int ac, t_data *data);
t_data	*indexing_of_stack(t_data *data);

// Parsing Functions
t_data	*get_joined_args(int ac, char **av, t_data *data);

#endif