/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:07:39 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/14 16:12:08 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	redirect_input(t_data *data, int i)
{
	int input_fd;

	input_fd = open(data->cmd[i].in.path, data->cmd[i].in.chmod);
	if (input_fd == -1)
		return_error(data->cmd[i].in.path, 2);
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		return_error("Minishell: Error: dup2 failed\n", 2);
		close(input_fd);
		exit(1);
	}
	close(input_fd);
	return ;
}

void	redirect_output(t_data *data, int i)
{
	int output_fd;

	output_fd = open(data->cmd[i].out.path, data->cmd[i].out.chmod);
	if (output_fd == -1)
		return_error(data->cmd[i].out.path, 2);
	if (dup2(output_fd, STDOUT_FILENO) == -1)
	{
		return_error("Minishell: Error: dup2 failed\n", 2);
		close(output_fd);
		exit(1);
	}
	close(output_fd);
	return ;
}