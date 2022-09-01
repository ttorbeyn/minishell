/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:07:39 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/26 17:18:54 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	redirections(t_data *data, t_pipes *pipe, int i)
{
	pipe->f_in = 0;
	pipe->f_out = 1;

	if(data->cmds[i].in.doc)
		pipe->f_in = open_heredoc(data->cmds[i].in.doc);
	if (data->cmds[i].in.path)
	{
		pipe->f_in = open(data->cmds[i].in.path, data->cmds[i].in.chmod);
		if (pipe->f_in < 0)
			return_error("Minishell: Error : No such file or directory", 2);
	}
	if (data->cmds[i].out.path)
	{
		pipe->f_in = open(data->cmds[i].out.path, data->cmds[i].out.chmod);
		if (pipe->f_out < 0)
			return_error("Minishell: Error : No such file or directory", 2);
	}
	return ;
}
