/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:18:39 by vic               #+#    #+#             */
/*   Updated: 2022/09/17 12:30:37 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	cmd_switch(t_data *data)
{
	t_pipes	p;

	if (data->nb_cmd == 1 && check_builtin(data->cmds[0].av[0])
		&& !data->cmds[0].in.doc && !data->cmds[0].in.path
		&& !data->cmds[0].out.path)
	{
		if (exec_builtin(data, 0, &p) == 42)
			return_error(data->cmds[0].av[0], ": Command not foundP", 127);
	}
	else
		lauching_process(data, &p);
	return (0);
}

int	exec_builtin(t_data *data, int i, t_pipes *pipe)
{
	if (!ft_strncmp(data->cmds[i].av[0], "cd", 2)
		&& ft_strlen(data->cmds[i].av[0]) == 2)
		return (exec_cd(data->cmds[i], data));
	if (!ft_strncmp(data->cmds[i].av[0], "echo", 4)
		&& ft_strlen(data->cmds[i].av[0]) == 4)
		return (exec_echo(data->cmds[i], pipe));
	if (!ft_strncmp(data->cmds[i].av[0], "exit", 4)
		&& ft_strlen(data->cmds[i].av[0]) == 4)
		return (exec_exit(data->cmds[i]));
	if (!ft_strncmp(data->cmds[i].av[0], "env", 3)
		&& ft_strlen(data->cmds[i].av[0]) == 3)
		return (exec_env(data->cmds[i], data, pipe));
	if (!ft_strncmp(data->cmds[i].av[0], "pwd", 3)
		&& ft_strlen(data->cmds[i].av[0]) == 3)
		return (exec_pwd(data, pipe));
	if (!ft_strncmp(data->cmds[i].av[0], "export", 6)
		&& ft_strlen(data->cmds[i].av[0]) == 6)
		return (exec_export(data->cmds[i], data));
	if (!ft_strncmp(data->cmds[i].av[0], "unset", 5)
		&& ft_strlen(data->cmds[i].av[0]) == 5)
		return (exec_unset(data->cmds[i], data));
	return (42);
}

void	executer(t_cmd cmd, t_data *data)
{
	char	*path;
	int		ret;

	ret = execve(cmd.av[0], cmd.av, data->envp);
	if (ret == -1)
	{
		path = check_path(data->envp, cmd.av[0]);
		ret = execve(path, cmd.av, data->envp);
		if (!path)
		{
			return_error_exit(cmd.av[0], ": Command not found", 127);
			return ;
		}
		else
			free(path);
	}
	if (ret == -1)
	{
		return_error_exit("Execution error", NULL, 127);
		// return ;
	}
	return ;
}
