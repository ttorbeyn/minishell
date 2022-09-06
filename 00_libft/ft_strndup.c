/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:05:48 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 20:05:49 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*cpy;

	if (len > (int)ft_strlen(s1))
		return (NULL);
	i = 0;
	cpy = malloc(sizeof(const char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (s1[i] && i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
