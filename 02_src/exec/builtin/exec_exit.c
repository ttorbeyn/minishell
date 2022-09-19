/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:14:59 by vic               #+#    #+#             */
/*   Updated: 2022/09/19 11:45:24 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_exit(t_cmd cmd)
{
	if (cmd.av[1])
	{
		if (!isdigit_check(cmd.av[1]))
			return(return_error_exit(cmd.av[1], ": numeric argument required", 255));
		return (exit(ft_atoi(cmd.av[1])), 1);
	}
	write(1, "exit\n", 5);
	return (exit(0), 1);
}
