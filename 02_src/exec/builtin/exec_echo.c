/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:59:37 by vic               #+#    #+#             */
/*   Updated: 2022/09/17 16:20:18 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	norm_bs(t_cmd command, t_pipes *p, int i, int flag)
{
	while (i < command.ac)
	{
		if (i != command.ac && i != flag + 1)
			write(1, " ", 1);
		ft_putstr_fd(command.av[i], p->f_out);
		i++;
	}
	return (i);
}

int	exec_echo(t_cmd command, t_pipes *p)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!command.av[1])
		return (write(p->f_out, "\n", 1));
	if (!ft_strncmp(command.av[i], "-n", 2))
	{
		if (ft_strlen(command.av[i]) > 2)
			return (return_error(command.av[i], ": unsupported flag", 2));
		flag++;
		i++;
		while (!ft_strncmp(command.av[i], "-n", 2) && command.av[i])
		{
			i++;
			flag++;
		}
	}
	i = norm_bs(command, p, i, flag);
	if (flag == 0)
		write(p->f_out, "\n", 1);
	return (0);
}
