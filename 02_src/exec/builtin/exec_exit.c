/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:14:59 by vic               #+#    #+#             */
/*   Updated: 2022/09/06 16:29:14 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_exit(t_cmd cmd)
{
	if (cmd.av[1])
	{
		if (!isdigit_check(cmd.av[1]))
			return_error(cmd.av[1], ": numeric argument required", 1);
	}
	write(1, "exit\n", 5);
	return (exit(0), 1);
}
