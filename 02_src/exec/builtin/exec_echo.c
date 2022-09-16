/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:59:37 by vic               #+#    #+#             */
/*   Updated: 2022/09/15 16:03:13 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_echo(t_cmd command)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!command.av[1])
		return (write(1, "\n", 1));
	if (!ft_strncmp(command.av[i], "-n", 2))
	{
		if (ft_strlen(command.av[i]) > 2)
			return_error(command.av[i], ": flag not found", 2);
		flag++;
		i++;
	}
	while (i < command.ac)
	{
		if (i != command.ac && i != flag + 1)
			write(1, " ", 1);
		ft_putstr_fd(command.av[i], 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	return (0);
}
