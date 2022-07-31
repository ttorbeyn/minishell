/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:18:39 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 20:13:02 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

char	*get_env_content(char *str, char **env)
{
	int i;
	char *tmp;
	char *target;

	i = 0;
	target = NULL;
	tmp = ft_strjoin(str, "=");
	while (env[i])
	{
		if (!ft_strncmp(env[i], tmp, ft_strlen(tmp)))
			target = ft_strdup(env[i]); //(=HOME)
		i++;
	}
	printf("%s/n", target);
	free(tmp);
	if (!target)
		return (NULL);
	return (target);
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

void	executer(char **path, char **cmd, char **env)
{
	int		i;
	int		ret;
	char	*tmp;

	ret = -1;
	i = -1;

	while (path[i] && ret == -1)
	{
		if (tmp)
			free(tmp);
		tmp = ft_strjoin(path[i], *cmd);
		if (!tmp)
			break;
		ret = execve(tmp, cmd, env);
		i++;
	}
	if (tmp)
		free(tmp);
	return ;
}