/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:07:39 by vmusunga          #+#    #+#             */
/*   Updated: 2022/09/15 15:25:49 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		g_exit = 130;
	}
}

void	signal_handler2(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		g_exit = 130;
	}
}

void	redirections(t_data *data, t_pipes *pipe, int i)
{
	char	*in;
	char	*out;

	pipe->f_in = 0;
	pipe->f_out = 1;
	if (data->cmds[i].in.doc)
		pipe->f_in = open_heredoc(data->cmds[i].in.doc);
	in = data->cmds[i].in.path;
	out = data->cmds[i].out.path;
	if (in)
	{
		pipe->f_in = open(data->cmds[i].in.path, data->cmds[i].in.chmod);
		if (pipe->f_in < 0)
			return_error(in, ": No such file or directory", 1);
	}
	if (out)
	{
		pipe->f_in = open(data->cmds[i].out.path, data->cmds[i].out.chmod);
		if (pipe->f_out < 0)
			return_error(out, ": No such file or directory", 1);
	}
	return ;
}
