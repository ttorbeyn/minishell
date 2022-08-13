/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:21:26 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/13 20:10:31 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	pipex(t_cmd *cmd, t_data *data)
{
	int pid;
	int pipe1[2];
	int pipe2[2];

	pid = fork();
	if (pid == -1)
		return (return_error("PANIC FORK ERROR", 2));
	first_cmd(cmd, data, pipe1);
}

void	first_child(t_data *data, t_cmd *cmd, int *pipe1)
{
	int exec;

	exec = 0;
	if (cmd[0].av[0])
		exec = 1;

	if (cmd[0].in.path)
		redirect_input(cmd, 0, data);
	if (cmd[0].out.path)
		redirect_output(cmd, 0, data);

	if (pipe1)
	{
		//pipe
		dup2(pipe1[1], STDOUT_FILENO);
		executer(cmd, data);
		
	}

	if (exec)
	{
		if (check_builtin(cmd))
			exec_builtin(cmd, data);
		else
			executer(cmd, data); //specify cmd[i]
	}
}

void	last_child();