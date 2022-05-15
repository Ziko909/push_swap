/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:29:41 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/14 08:57:18 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap_bonus.h"

char	*ft_read_fd(char *rest, int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_search_new_line(rest))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
		{
			if (i == 0 && rest)
				break ;
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free (buffer);
	return (rest);
}

int	ft_search_new_line(char *rest)
{
	int	i;

	i = 0;
	if (!rest)
		return (0);
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_end(char *rest)
{
	int	i;

	i = 0;
	if (!rest)
		return (1);
	if (rest[0] == '\0')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line_;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_fd(rest, fd);
	line_ = ft_line_(rest);
	rest = ft_next_line(rest);
	if (ft_end(rest) && ft_end(line_))
		return (free(line_), NULL);
	return (line_);
}
