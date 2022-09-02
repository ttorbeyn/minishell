/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:18:39 by vic               #+#    #+#             */
/*   Updated: 2022/09/02 16:32:42 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	cmd_switch(t_data *data)
{
	t_pipes p;

	// if (data->nb_cmd == 1)
	// {
	// 	if (check_builtin(data->cmds[0].av[0]))
	// 		exec_builtin(data, 0, &p);
	// 	else
	// 		executer(data->cmds[0], data);
	// }
	// else
		lauching_process(data, &p);
	return (0);
}

int	exec_old_builtin(t_data *data, int i)
{
	if (!ft_strncmp(data->cmds[i].av[0], "cd", 2))
		return (exec_cd(data->cmds[i], data));
	if (!ft_strncmp(data->cmds[i].av[0], "echo", 4))
		return (exec_echo(data->cmds[i]));
	if (!ft_strncmp(data->cmds[i].av[0], "exit", 4))
		return (3);
	//  if (!ft_strncmp(data->cmds[i].av[0], "env", 3))
	//  	return (exec_env(data->cmds[i], data));
	//  if (!ft_strncmp(data->cmds[i].av[0], "pwd", 3))
	//  	return (exec_pwd(data, pipe));
	if (!ft_strncmp(data->cmds[i].av[0], "export", 6))
		return (exec_export(data->cmds[i], data));
	if (!ft_strncmp(data->cmds[i].av[0], "unset", 5))
		return (exec_unset(data->cmds[i], data));
	return (0);
}

int	exec_builtin(t_data *data, int i, t_pipes *pipe)
{
	if (!ft_strncmp(data->cmds[i].av[0], "cd", 2))
		return (exec_cd(data->cmds[i], data));
	if (!ft_strncmp(data->cmds[i].av[0], "echo", 4))
		return (exec_echo(data->cmds[i]));
	if (!ft_strncmp(data->cmds[i].av[0], "exit", 4))
		return (exec_exit(data->cmds[i]));
	if (!ft_strncmp(data->cmds[i].av[0], "env", 3))
		return (exec_env(data->cmds[i], data, pipe));
	if (!ft_strncmp(data->cmds[i].av[0], "pwd", 3))
		return (exec_pwd(data, pipe));
	if (!ft_strncmp(data->cmds[i].av[0], "export", 6))
		return (exec_export(data->cmds[i], data));
	if (!ft_strncmp(data->cmds[i].av[0], "unset", 5))
		return (exec_unset(data->cmds[i], data));
	return (0);
}

void	executer(t_cmd cmd, t_data *data)
{
	char	*path;
	int ret;

	path = check_path(data->envp, cmd.av[0]);
	ret = execve(path, cmd.av, data->envp);
	if (!path)
	{
		return_error(cmd.av[0], ": Command not found", 0);
		return;
	}
	else
		free(path);
	if (ret == -1)
	{
		return_error("Execution error", NULL, 127);
		return;
	}
	return ;
}
