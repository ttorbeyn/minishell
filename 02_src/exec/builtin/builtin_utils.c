/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:33:24 by vmusunga          #+#    #+#             */
/*   Updated: 2022/07/31 22:57:02 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

char	*get_env_content(char *name, t_list *env)
{
	char *tmp;
	char *target;
	char *content;

	target = NULL;
	tmp = ft_strjoin(name, "=");
	while (env)
	{
		content = (char*)env->content;
		if (!ft_strncmp(content, tmp, ft_strlen(tmp)))
			target = ft_strdup(content); //(=HOME)
		env = env->next;
	}
	free(tmp);
	if (target)
		free(target);
	return (target);
}

char	*get_env_name(char *str)
{
	int i;
	int len;
	char *cpy;

	i = 0;
	len = 0;
	while (str[len])
	{
		if (str[len] == '=')
			break;
		len++;
	}
	cpy = malloc(sizeof(char) * len + 1);
	while (i < len + 1)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "cd", 2))
		return (1);
	if (!ft_strncmp(cmd, "echo", 4))
		return (2);
	if (!ft_strncmp(cmd, "exit", 4))
		return (3);
	if (!ft_strncmp(cmd, "env", 3))
		return (4);
	if (!ft_strncmp(cmd, "setenv", 6))
		return (5);
	if (!ft_strncmp(cmd, "unsetenv", 8))
		return (6);
	return (0);
}