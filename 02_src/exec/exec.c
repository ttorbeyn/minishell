/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:18:39 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 22:37:59 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	executer(char **path, char **cmd, char **env)
{
	int		i;
	int		ret;
	char	*tmp;

	ret = -1;
	i = -1;

	while (path[i] && ret == -1)
	{
		if (tmp)
			free(tmp);
		tmp = ft_strjoin(path[i], *cmd);
		if (!tmp)
			break;
		ret = execve(tmp, cmd, env);
		i++;
	}
	if (tmp)
		free(tmp);
	return ;
}