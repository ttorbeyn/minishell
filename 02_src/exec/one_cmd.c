/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:20:58 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/14 14:09:54 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	one_cmd(t_data *data)
{
	if (check_builtin(data->cmd[0].cmd))
		exec_builtin(data, 0);
	else
		executer(data->cmd[0], data);
	return (0);
}
