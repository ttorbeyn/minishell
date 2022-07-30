/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:36:41 by vic               #+#    #+#             */
/*   Updated: 2022/07/30 16:48:36 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_env(t_command command, char **envp)
{
	int i;

	i = 0;
	if (command.ac > 2)
	{
		ft_putendl_fd("Error: Too many arguments", 2);
		return (1);
	}
	if (!envp)
		return (1);
	while (envp[i])
	{
		ft_putstr_fd(envp[i], 1);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}