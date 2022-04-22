
#include "push_swap.h"

// char    *ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*nstr;
// 	if (!s1) 
// 		s1 = ft_strdup("");

// 	i = 0;
// 	j = 0;
// 	while (s1[i] != '\0')
// 		i++;
// 	while (s2[i])
// 		i++;
// 	nstr = (char *) malloc((i + 1) * sizeof(char));
// 	if (!nstr)
// 		return(NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		nstr[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 		nstr[i++] = s2[j++];
// 	nstr[i] = '\0';
// 	return (nstr);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:30:29 by zaabou            #+#    #+#             */
/*   Updated: 2021/11/21 02:58:24 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
char    *ft_strjoin(char *s1, char *s2)
{
        size_t  lns;
        char    *nws;
        size_t  i;
        size_t  j;

        if (!s1 || !s2)
                return (NULL);
        lns = ft_strlen(s1) + ft_strlen(s2);
        i = 0;
        j = 0;
        nws = (char *) malloc(lns + 1);
        if (nws == '\0')
                return (NULL);
        while (s1[j])
        {
                nws[i++] = s1[j++];
        }
        j = 0;
        while (s2[j])
        {
                nws[i++] = s2[j++];
        }
        nws[i] = '\0';
        return (nws);
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

	i = 0;
	x = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
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

size_t  ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int		t;
	int				r;
	int				i;

	i = 0;
	r = 1;
	t = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == '-')
		{
			r *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		t = t * 10 + str[i] - 48;
		i++;
	}
	return (r * t);
}