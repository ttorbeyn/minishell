/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:59:37 by vic               #+#    #+#             */
/*   Updated: 2022/08/13 23:27:00 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_echo(t_cmd command)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	if (!command.av[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	if (command.av[i] && command.av[i][0] == '-' && command.av[i][1] == 'n')
	{
		flag++;
		i++;
	}
	while (command.av[i])
	{
		if (i != command.ac - 1 && i != 1)
			write(1, " ", 1);
		ft_putstr_fd(command.av[i], 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	return (0);
}