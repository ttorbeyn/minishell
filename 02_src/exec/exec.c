/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:18:39 by vic               #+#    #+#             */
/*   Updated: 2022/08/13 14:24:32 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	executer(t_cmd *cmd, t_data *data)
{
	char	*path;
	int ret;

	path = check_path(data->envp, cmd->cmd);
	ret = execve(path, cmd->av, data->envp);
	if (!path)
		return_error("Path not found", 0);
	else
		free(path);
	if (ret == -1)
		return_error("Execution error", 2);
	return ;
}

// void	child_one(t_data *data, t_cmd *cmd)
// {
	
// }
