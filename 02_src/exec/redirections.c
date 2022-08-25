/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:07:39 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/25 18:14:01 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	redirections(t_data *data, t_pipes *pipe, int i)
{
	pipe->f_in = 0;
	pipe->f_out = 1;

	if (data->cmd[i].in.path)
	{
		pipe->f_in = open(data->cmd[i].in.path, data->cmd[i].in.chmod);
		if (pipe->f_in < 0)
			return_error("Minishell: Error : No such file or directory", 2);
	}
	if (data->cmd[i].out.path)
	{
		pipe->f_in = open(data->cmd[i].out.path, data->cmd[i].out.chmod);
		if (pipe->f_out < 0)
			return_error("Minishell: Error : No such file or directory", 2);
	}
	return ;
}
