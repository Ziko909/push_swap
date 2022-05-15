/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:30:31 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/13 19:23:22 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strjoine(char *rest, char *buffer);
int		ft_2strlen(char *rest, char *buffer);
int		ft_search_new_line(char *rest);
char	*get_next_line(int fd);
char	*ft_line_(char *rest);
char	*ft_next_line(char *rest);
char	*ft_read(char *rest, char *buffer, int fd);
int		ft_end(char *rest);
#endif
