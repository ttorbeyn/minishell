/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:20:58 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/13 20:11:06 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	one_cmd(t_cmd *cmd, t_data *data) //bullshit
{
	if (check_builtin(cmd))
		exec_builtin(cmd, data);
	else
		executer(cmd, data);
	return (0);
}

