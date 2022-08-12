/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:20:58 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/12 20:10:35 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	one_cmd(t_cmd *cmd, t_data *data)
{
	//check buitin
	executer(cmd, data);
	return (0);
	//forks
}

// void	child_one(t_data *data, t_cmd *cmd)
// {
	
// }