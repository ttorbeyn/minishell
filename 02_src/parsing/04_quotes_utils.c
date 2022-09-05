/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_quotes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:28:21 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:28:22 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

char	*double_join(char*s1, char *s2)
{
	if (s1 && s2)
		return (ft_strjoin(s1, s2));
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return (NULL);
}

char	*triple_join(char *s1, char *s2, char *s3)
{
	char	*new;

	new = NULL;
	if (s1 && s2 && s3)
	{
		new = ft_strjoin(s1, s2);
		new = ft_strjoin(new, s3);
	}
	if (!s1 && s2 && s3)
		new = ft_strjoin(s2, s3);
	if (s1 && !s2 && s3)
		new = ft_strjoin(s1, s3);
	if (s1 && s2 && !s3)
		new = ft_strjoin(s1, s2);
	if (!s1 && !s2)
		return (s3);
	if (!s1 && !s3)
		return (s2);
	if (!s2 && !s3)
		return (s1);
	return (new);
}
