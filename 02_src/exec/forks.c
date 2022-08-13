/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:23:13 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/13 19:51:06 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	first_cmd(t_cmd *cmd, t_data *data, int *pipe1)	//SUPOSED OK
{
	int	pid;

	if (pipe(pipe1) == -1)
		return (return_error("PANIC PIPE ERROR", 2));
	pid = fork();
	if (pid == -1)
		return (return_error("PANIC FORK ERROR", 2));
	if (pid == 0)
		first_child(cmd, data, pipe1);
	close(pipe1[1]);
	return (0);
}

int	last_cmd(t_cmd *cmd, t_data *data, int *pipein, int pid)
{

}
