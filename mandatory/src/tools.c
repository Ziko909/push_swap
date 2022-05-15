/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:28:06 by zaabou            #+#    #+#             */
/*   Updated: 2022/05/15 13:05:55 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lns;
	char	*nws;
	size_t	i;
	size_t	j;

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
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		ss = (char *) malloc(((ft_strlen(s) - start) + 1));
	else
		ss = (char *) malloc((len + 1));
	if (!ss)
		return (NULL);
	while (s[i] && i < start)
		i++;
	while (s[i] && len)
	{
		ss[j++] = s[i++];
		len--;
	}
	ss[j] = '\0';
	return (ss);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		x;
	char	*y;

	if (!s1)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[i])
		i++;
	y = (char *) malloc(i * sizeof(char) + 1);
	if (!y)
		return (NULL);
	while (s1[x])
	{
		y[x] = s1[x];
		x++;
	}
	y[x] = '\0';
	return (y);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str, t_data *data)
{
	long int		t;
	int				r;
	int				i;

	i = 0;
	r = 1;
	t = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == '-')
			r *= -1;
		if (!ft_isdigit(str[i]))
			ft_error(data);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		t = t * 10 + str[i++] - 48;
		if ((t * r) > 2147483647 || (t * r) < -2147483648)
			ft_error(data);
	}
	if (str[i] && !ft_isdigit(str[i]))
		ft_error(data);
	return (r * t);
}
