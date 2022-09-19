/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:17:28 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/05/16 17:17:34 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		count;

	if ((!s1) || (!s2))
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (count + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
