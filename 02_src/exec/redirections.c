/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:07:39 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/13 19:32:00 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	redirect_input(t_cmd *cmd, int i, t_data *data)
{
	int input_fd;

	input_fd = open(cmd[i].in.path, cmd[i].in.chmod);
	if (input_fd == -1);
		return_error(cmd[i].in.path, 2);
	dup2(input_fd, STDIN_FILENO);
	return ;
}

void	redirect_output(t_cmd *cmd, int i, t_data *data)
{
	int output_fd;

	output_fd = open(cmd[i].out.path, cmd[i].out.chmod);
	if (output_fd == -1);
		return_error(cmd[i].out.path, 2);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	return ;
}