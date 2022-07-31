/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:40:09 by vic               #+#    #+#             */
/*   Updated: 2022/07/30 18:16:46 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	get_path(char *str, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], str, ft_strlen(str)))
			return (i);
		i++;
	}
	return (-1);
}

int	set_dir(char *path, char ***envp)
{
	int ret;

	ret = chdir(path);
	if (ret == -1)
		return (-1);
	// then change the current path in struct ??
}

int	exec_cd(t_command command, char **envp)
{
	char *path;
	int ret;

	if (!command.av[1])
	{
		path = get_env_content("HOME", envp);
		if (!path)
		{
			ft_putendl_fd("Error: No home set", 2);
			return (1);
		}
		ret = set_dir(path, &envp);
		free(path);
		return (ret);
	}
	if (command.av[2])
	{
		ft_putendl_fd("Error: Too many arguments", 2);
		return (1);
	}
	if (command.av[1][0] == '\0')
		return (set_dir(".", &envp));
	return (set_dir(command.av[1], &envp));
}
