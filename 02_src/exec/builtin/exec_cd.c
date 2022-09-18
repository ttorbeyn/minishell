/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:40:09 by vic               #+#    #+#             */
/*   Updated: 2022/09/18 16:39:08 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

char	*get_path(t_cmd command, t_data *data)
{
	char		*path;
	const char	*home;

	path = NULL;
	home = get_env_content("HOME", data->env);
	if (command.av[1])
	{
		path = getcwd(NULL, 0);
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, command.av[1]);
	}
	else
		chdir(home);
	return (path);
}

void	update_env(t_data *data, char *name)
{
	char	*content;
	t_list	*tmp;
	char	*path;

	tmp = data->env;
	while (tmp)
	{
		content = (char *) tmp->content;
		if (!ft_strncmp(name, content, ft_strlen(name)))
		{
			path = get_pwd();
			tmp->content = ft_strjoin(name, path);
			if (!content)
				exit(EXIT_FAILURE);
			free(path);
			break ;
		}
		tmp = tmp->next;
	}
	return ;
}

int	exec_cd(t_cmd command, t_data *data)
{
	char	*path;

	update_env(data, "OLDPWD=");
	path = get_path(command, data);
	if (!path && !command.av[1])
	{
		update_env(data, "PWD=");
		return (0);
	}
	if (chdir(path) < 0 && command.av[1])
	{
		free(path);
		return (return_error("Error: Path not found", NULL, 1));
	}
	update_env(data, "PWD=");
	return (0);
}
