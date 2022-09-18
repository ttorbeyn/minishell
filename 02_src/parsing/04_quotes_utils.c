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

char	*double_join(char *s1, char *s2)
{
	char	*new;

	if (s1 && s2)
	{
		new = ft_strjoin(s1, s2);
		return (new);
	}
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return (NULL);
}

char	*triple_join(char *s1, char *s2, char *s3)
{
	char	*new;
	char	*tmp;

	new = NULL;
	if (s1 && s2 && s3)
	{
		tmp = ft_strjoin(s1, s2);
		new = ft_strjoin(tmp, s3);
		free(tmp);
	}
	if (!s1 && s2 && s3)
		new = ft_strjoin(s2, s3);
	if (s1 && !s2 && s3)
		new = ft_strjoin(s1, s3);
	if (s1 && s2 && !s3)
		new = ft_strjoin(s1, s2);
	if (!s1 && !s2 && s3)
		return (ft_strdup(s3));
	if (!s1 && !s3 && s2)
		return (ft_strdup(s2));
	if (!s2 && !s3 && s1)
		return (ft_strdup(s1));
	return (new);
}
