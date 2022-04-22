/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:45:26 by zaabou            #+#    #+#             */
/*   Updated: 2022/04/17 23:43:27 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"
static	int	countewds(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != c)
		j++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

static	int	end(char const *s, char c, int st)
{
	while (s[st])
	{
		if (s[st] == c)
			return (st);
		st++;
	}
	return (st);
}

static	char	**freespl(char **spl, int i)
{
	while (i--)
		free (spl[i]);
	free (spl);
	return (spl);
}

static	char	**splfill(char **spl, char c, char const *s)
{
	int	i;
	int	k;
	int	m;

	i = 0;
	k = 0;
	m = 0;
	while (s[m] != '\0' && i < countewds(s, c))
	{
		if (s[m] == c)
			m++;
		else if (s[m] != c)
		{
			k = end(s, c, m);
			spl[i] = ft_substr(s, m, k - m);
			if (!spl[i])
				return (freespl(spl, i));
			i++;
			m = k;
		}
	}
	spl[i] = 0;
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;

	if (!s)
		return (NULL);
	spl = (char **) malloc((countewds(s, c) + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	spl = splfill(spl, c, s);
	return (spl);
}
