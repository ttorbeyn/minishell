/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:21:26 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/14 16:10:39 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"


void	first_child(t_data *data, int *pipe1)
{
	int exist;

	exist = 0;
	if (data->cmd[0].av[0])
		exist = 1;

	if (data->cmd[0].in.path)
		redirect_input(data, 0);
	if (data->cmd[0].out.path)
		redirect_output(data, 0);

	else if (pipe1)
	{
		if (dup2(pipe1[1], STDOUT_FILENO) == -1)
			return_error("Minishell: Error: dup2 failed\n", 2);
		close(pipe1[0]);
		close(pipe1[1]);
	}

	if (exist)
	{
		if (check_builtin(data->cmd[0].cmd))
			exec_builtin(data, 0);
		else
			executer(data->cmd[0], data);
	}
	exit(0);
}

void	last_child(t_data *data, int *pipein, int i)
{
	int exist;

	exist = 0;
	if (data->cmd[i].av[0])
		exist = 1;

	if (data->cmd[i].in.path)
		redirect_input(data, i);
	if (data->cmd[0].out.path)
		redirect_output(data, 0);

	else if (dup2(pipein[0], STDIN_FILENO) == -1)
		return_error("Minishell: Error: dup2 failed\n", 2);
	close(pipein[0]);
	close(pipein[1]);

	if (exist)
	{
		if (check_builtin(data->cmd[0].cmd))
			exec_builtin(data, i);
		else
			executer(data->cmd[i], data);
	}
	exit(0);
}