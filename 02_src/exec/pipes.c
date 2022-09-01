/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:21:26 by vmusunga          #+#    #+#             */
/*   Updated: 2022/09/01 18:09:41 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"


void	child_process(t_data *data, t_pipes *pipe, int i)
{
	redirections(data, pipe, i);
	if (pipe->f_in != 0)
		short_dup(pipe->f_in, 0);
	if (pipe->f_out != 1)
		short_dup(pipe->f_out, 1);

	if (i > 0)
		dup_close_pipe(pipe->old_end[0], pipe->f_in, pipe->old_end);
	if (i + 1 < data->nb_cmd)
		dup_close_pipe(pipe->new_end[1], pipe->f_out, pipe->new_end);

	if (check_builtin(data->cmds[i].av[0]))
	{
			exec_builtin(data, i, pipe);
			exit(0);
	}
	else
			executer(data->cmds[i], data);
	return ;
}

void	parent_process(t_data *data, t_pipes *pipe, int pid, int i)
{
	if (i > 0)
		close_pipe(pipe->old_end);
	if (i + 1 < data->nb_cmd)
	{
		pipe->old_end[0] = pipe->new_end[0];
		pipe->old_end[1] = pipe->new_end[1];
	}
	waitpid(pid, NULL, 0);
}

void	ft_fork(t_data *data, t_pipes *pipe, int i)
{
	int pid;

	pid = fork();
	if (pid == -1)
		return_error("Minishell: Error: fork error", 2);
	if (pid == 0)
	{
		child_process(data, pipe, i);
		// waitpid(pid, NULL, 0);
		exit (0);
	}
	else
		parent_process(data, pipe, pid, i);
	return ;
}

void	lauching_process(t_data *data)
{
	int i;
	t_pipes p;

	i = 0;
	while (i < data->nb_cmd)
	{
		if (i + 1 < data->nb_cmd)
		{
			if (pipe(p.new_end))
			{
				return_error("Minishell: pipe error", 2);
				return ;
			}
		}
		ft_fork(data, &p, i);
		i++;
	}
	return ;
}