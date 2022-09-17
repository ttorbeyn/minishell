/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:59:37 by vic               #+#    #+#             */
/*   Updated: 2022/09/17 18:52:05 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

// void	norm_bs2(t_cmd command, int i, int **flag)
// {
// 	int x;

// 	while (command.av[i])
// 	{
// 		if (!ft_strncmp(command.av[i], "-n", 2))
// 		{
// 			x = 1;
// 			(*flag)++;
// 			while (command.av[i][x] && !ft_strncmp(&command.av[i][x], "n", 1))
// 				x++;
// 			if (command.av[i][x] && ft_strncmp(&command.av[i][x], "n", 1))
// 			{
// 				(*flag) = 0;
// 				break ;
// 			}
// 			else
// 				i++;
// 		}
// 		else
// 			break ;
// 	}
// }

void	norm_bs(t_cmd command, t_pipes *p, int i, int flag)
{
	while (i < command.ac)
	{
		if (i != command.ac && i != flag + 1)
			write(1, " ", 1);
		ft_putstr_fd(command.av[i], p->f_out);
		i++;
	}
	if (flag == 0)
		write(p->f_out, "\n", 1);
	return ;
}

int	exec_echo(t_cmd command, t_pipes *p)
{
	int	i;
	int	flag;
	int	x;

	i = 1;
	flag = 0;
	if (!command.av[1])
		return (write(p->f_out, "\n", 1));
	while (command.av[i])
	{
		if (!ft_strncmp(command.av[i], "-n", 2))
		{
			x = 1;
			flag++;
			while (command.av[i][x] && !ft_strncmp(&command.av[i][x], "n", 1))
				x++;
			if (command.av[i][x] && ft_strncmp(&command.av[i][x], "n", 1))
			{
				flag = 0;
				break ;
			}
			else
				i++;
		}
		else
			break ;
	}
	norm_bs(command, p, i, flag);
	return (0);
}