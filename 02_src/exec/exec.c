/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:18:39 by vic               #+#    #+#             */
/*   Updated: 2022/08/14 16:42:40 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	cmd_switch(t_data *data)
{
	if (data->cmd_count == 1)
	{
		if (one_cmd(data))
			return (1);
	}
	else
		if (pipex(data))
			return (1);
	return (0);
}

int	exec_builtin(t_data *data, int i)
{
	if (!ft_strncmp(data->cmd[i].av[0], "cd", 2))
		return (exec_cd(data->cmd[i], data));
	if (!ft_strncmp(data->cmd[i].av[0], "echo", 4))
		return (exec_echo(data->cmd[i]));
	if (!ft_strncmp(data->cmd[i].av[0], "exit", 4))
		return (3);
	if (!ft_strncmp(data->cmd[i].av[0], "env", 3))
		return (exec_env(data->cmd[i], data));
	if (!ft_strncmp(data->cmd[i].av[0], "pwd", 3))
		return (exec_pwd(data));
	if (!ft_strncmp(data->cmd[i].av[0], "export", 6))
		return (exec_export(data->cmd[i], data));
	if (!ft_strncmp(data->cmd[i].av[0], "unset", 5))
		return (exec_unset(data->cmd[i], data));
	return (0);
}

void	executer(t_cmd cmd, t_data *data) //send precise cmd[i]
{
	char	*path;
	int ret;

	path = check_path(data->envp, cmd.cmd);
	ret = execve(path, cmd.av, data->envp);
	if (!path)
		return_error("Path not found", 0);
	else
		free(path);
	if (ret == -1)
		return_error("Execution error", 2);
	return ;
}


