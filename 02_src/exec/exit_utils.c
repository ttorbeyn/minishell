/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:26:38 by vmusunga          #+#    #+#             */
/*   Updated: 2022/09/17 16:26:59 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	return_error(char *msg, char *msg2, int system)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(msg, 2);
	if (msg2)
		ft_putstr_fd(msg2, 2);
	write(2, "\n", 1);
	g_exit = WEXITSTATUS(system);
	return (system);
}

int	return_error_exit(char *msg, char *msg2, int system)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(msg, 2);
	if (msg2)
		ft_putstr_fd(msg2, 2);
	write(2, "\n", 1);
	g_exit = system;
	WEXITSTATUS(system);
	exit(system);
}

void	ft_abort(char *str)
{
	return_error(str, NULL, 255);
	exit(0);
}
