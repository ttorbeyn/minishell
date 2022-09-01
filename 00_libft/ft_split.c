/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:26 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/13 13:44:36 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

static int	ft_wordcount(char const *s, char c)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	if (s[i] != c && s[i])
	{
		x++;
		i++;
	}
	else if (s[i])
		i++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			x++;
		i++;
	}
	return (x);
}

static int	ft_wordlen(char const *s, char c, size_t x)
{
	size_t	i;

	i = 0;
	while (s[x] && s[x] == c)
		x++;
	while (s[x] && s[x] != c)
	{
		x++;
		i++;
	}
	return (i);
}

static char	**ft_freeall(char **new, int i)
{
	int	j;

	j = 0;
	while (j < i && new[j])
	{
		free(new[j]);
		j++;
	}
	free(new);
	ft_panic("Error : ft_split\n");
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	size_t	j;
	size_t	x;

	new = malloc((sizeof(char *)) * (ft_wordcount(s, c) + 1));
	if (!new || !s)
		ft_panic("Error : ft_split\n");
	i = -1;
	x = 0;
	while (++i < (ft_wordcount(s, c)))
	{
		j = 0;
		new[i] = malloc((sizeof(char) * (ft_wordlen(s, c, x) + 1)));
		if (!new[i])
			ft_freeall(new, i);
		while (s[x] && s[x] == c)
			x++;
		while (s[x] && s[x] != c)
			new[i][j++] = s[x++];
		new[i][j] = '\0';
	}
	new[i] = NULL;
	return (new);
}
