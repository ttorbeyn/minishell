/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:40:09 by vic               #+#    #+#             */
/*   Updated: 2022/08/31 18:03:48 by vmusunga         ###   ########.fr       */
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
			// ft_putstr_fd(path, 2);
			// fflush(stdout);
			tmp->content = ft_strjoin(name, path);
			if (!content)
				exit(EXIT_FAILURE);
			free(path);
			break ;
		}
		tmp = tmp->next;
	}
	return;
}

int	exec_cd(t_cmd command, t_data *data)
{
	char *path;
	update_env(data, "OLDPWD=");
	path = get_path(command, data);
	if (!path)
		return (1);

	// ft_putstr_fd(path, 2);
	// fflush(stdout);
	if (chdir(path) < 0)
	{
		return_error("Error: Path not found", 0);
		free(path);
		return (1);
	}
	// ft_putstr_fd("ALO\n", 2);
	// fflush(stdout);
	update_env(data, "PWD=");
	print_lst(&data->env);
	free(path);
	return (0);
}
