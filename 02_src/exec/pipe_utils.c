/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:29:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/25 18:52:59 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	short_dup(int x, int y)
{
	int	ret;

	ret = dup2(x, y);
	if (ret == -1)
	{
		return_error("Minishell: Error: dup failed\n", 2);
		exit(1);
	}
}

void	close_pipe(int *end)
{
	int	r;

	r = close(end[0]);
	if (r == -1)
	{
		return_error("Minishell: Error: pipe failed\n", 2);
		exit(1);
	}
	r = close(end[1]);
	if (r == -1)
	{
		return_error("Minishell: Error: pipe failed\n", 2);
		exit(1);
	}
}

void	dup_close_pipe(int end, int fd, int *ends)
{
	short_dup(end, fd);
	close_pipe(ends);
}
