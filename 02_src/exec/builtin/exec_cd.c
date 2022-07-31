/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:40:09 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 20:13:02 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	get_path(char *str, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, ft_strlen(str)))
			return (i);
		i++;
	}
	return (-1);
}

int	set_dir(char *path, char ***env)
{
	int ret;

	ret = chdir(path);
	if (ret == -1)
		return (-1);
	// then change the current path in struct ??
}

int	exec_cd(t_cmd command, char **env)
{
	char *path;
	int ret;

	if (!command.av[1])
	{
		path = get_env_content("HOME", env);
		if (!path)
		{
			ft_putendl_fd("Error: No home set", 2);
			return (1);
		}
		ret = set_dir(path, &env);
		free(path);
		return (ret);
	}
	if (command.av[2])
	{
		ft_putendl_fd("Error: Too many arguments", 2);
		return (1);
	}
	if (command.av[1][0] == '\0')
		return (set_dir(".", &env));
	return (set_dir(command.av[1], &env));
}
