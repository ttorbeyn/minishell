/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:46:26 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/03 15:26:16 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

static int	ft_countw(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static int	ft_len(char const *str, char c)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	if (str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		i++;
		x++;
	}
	return (x);
}

static char	**ft_free(char **tab, int x)
{
	int	i;

	i = 0;
	while (i < x && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c, int i)
{
	char	**dest;
	int		x;
	int		y;

	i = 0;
	x = 0;
	if ((!s))
		return (NULL);
	dest = malloc(sizeof(char **) * (ft_countw(s, c) + 1));
	if (!dest)
		return (NULL);
	while (x < ft_countw(s, c))
	{
		y = 0;
		dest[x] = malloc(sizeof(char *) * (ft_len(&s[i], c) + 1));
		if (!dest[x])
			return (ft_free(dest, x));
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			dest[x][y++] = s[i++];
		dest[x++][y] = '\0';
	}
	dest[x] = 0;
	return (dest);
}
