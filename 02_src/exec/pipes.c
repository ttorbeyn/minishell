/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:21:26 by vmusunga          #+#    #+#             */
/*   Updated: 2022/09/16 23:40:54 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	child_process(t_data *data, t_pipes *pipe, int i)
{
	redirections(data, pipe, i);
	if (pipe->f_in != 0)
		short_dup(pipe->f_in, 0);
	if (pipe->f_out != 1)
	{
		short_dup(pipe->f_out, 1);
		printf("\nGOT IT\n");
	}
	if (i > 0)
		dup_close_pipe(pipe->old_end[0], pipe->f_in, pipe->old_end);
	if (i + 1 < data->nb_cmd)
		dup_close_pipe(pipe->new_end[1], pipe->f_out, pipe->new_end);
	if (check_builtin(data->cmds[i].av[0]))
	{
		if (exec_builtin(data, 0, pipe) == 42)
			return_error(data->cmds[0].av[0], ": Command not found", 0);
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
	int	pid;

	pid = fork();
	if (pid == -1)
		return_error("Error : fork error", NULL, 2);
	if (pid == 0)
	{
		if (!data->cmds[i].in.doc)
			signal(SIGQUIT, SIG_DFL);
		child_process(data, pipe, i);
		exit (0);
	}
	else
		parent_process(data, pipe, pid, i);
	return ;
}

void	lauching_process(t_data *data, t_pipes *p)
{
	int	i;

	i = 0;
	while (i < data->nb_cmd)
	{
		if (i + 1 < data->nb_cmd)
		{
			if (pipe(p->new_end))
			{
				return_error("Error : pipe error", NULL, 2);
				return ;
			}
		}
		if (data->cmds[i].in.doc)
			signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, signal_handler);
		ft_fork(data, p, i);
		i++;
	}
	return ;
}
