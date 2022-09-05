/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:20:44 by vmusunga          #+#    #+#             */
/*   Updated: 2022/07/31 18:21:40 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return (&((char *)s)[i]);
	}
	while (s[i] != ((char)c) && s[i])
		i++;
	if (s[i] == ((char)c))
		return (&((char *)s)[i]);
	return (0);
}
