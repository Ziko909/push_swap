/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:29:59 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/14 08:57:52 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap_bonus.h"

/*char    *ft_strjoin(char *s1, char *s2)
{
	size_t  lns;
	char    *nws;
	size_t  i;
	size_t  j;
	
	if (!s1)
		return (ft_strdup(s2));
	lns = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	nws = (char *) malloc(lns + 1);
	if (!nws)
		return (NULL);
	while (s1[j])
		nws[i++] = s1[j++];
	j = 0;
	while (s2[j])
		nws[i++] = s2[j++];
	nws[i] = '\0';
	return (free(s1), nws);
}*/

int	ft_2strlen(char *rest, char *buffer)
{
	int	i;
	int	j;

	if (!rest && !buffer)
		return (0);
	i = 0;
	j = 0;
	while (buffer[i])
		i++;
	if (!rest)
		return (i);
	while (rest[j])
		j++;
	return (i + j);
}

char	*ft_line_(char *rest)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	j = 0;
	if (!rest)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (rest[j] && rest[j] != '\n')
	{
		line[j] = rest[j];
		j++;
	}
	if (rest[j] && rest[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_next_line(char *rest)
{
	int		i;
	int		j;
	char	*next_line;

	if (!rest)
		return (NULL);
	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
		return (free(rest), NULL);
	i++;
	next_line = (char *) malloc(ft_2strlen(NULL, rest) - i + 1);
	if (!next_line)
		return (NULL);
	while (rest[i])
		next_line[j++] = rest[i++];
	next_line[j] = '\0';
	free(rest);
	return (next_line);
}
