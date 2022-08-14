/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:23:13 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/14 16:42:01 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	first_cmd(t_data *data, int *pipe1)	//SUPOSED OK
{
	int	pid;

	if (pipe(pipe1) == -1)
		return (return_error("PANIC PIPE ERROR", 2));
	pid = fork();
	if (pid == -1)
		return (return_error("PANIC FORK ERROR", 2));
	if (pid == 0)
		first_child(data, pipe1);
	close(pipe1[1]);
	return (0);
}

void	last_cmd(t_data *data, int *pipein, int pid)
{
	int i;

	i = data->cmd_count - 1;
	if (pid == 0)
		last_child(data, pipein, i);
	close(pipein[0]);
	close(pipein[1]);
}

int	pipex(t_data *data)
{
	int pid;
	int pipe1[2];
	// int pipe2[2];
	printf("ALO	");
	
	// signal(SIGINT, sig_handler_fork);
	if (first_cmd(data, pipe1) == 1)
		return (1);

	pid = fork();
	if (pid == -1)
		return (return_error("PANIC FORK ERROR", 2));
	// wait(100);
	printf("ALO	");
	last_cmd(data, pipe1, pid);
	return (0);
}