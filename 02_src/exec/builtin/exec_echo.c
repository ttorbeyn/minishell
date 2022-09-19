/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:59:37 by vic               #+#    #+#             */
/*   Updated: 2022/09/19 19:18:08 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	norm_bs2(t_cmd command, int i, int *flag)
{
	int	x;

	while (command.av[i])
	{
		if (!ft_strncmp(command.av[i], "-n", 2))
		{
			x = 1;
			(*flag)++;
			while (command.av[i][x] && !ft_strncmp(&command.av[i][x], "n", 1))
				x++;
			if (command.av[i][x] && ft_strncmp(&command.av[i][x], "n", 1))
			{
				(*flag) = 0;
				break ;
			}
			else
				i++;
		}
		else
			break ;
	}
	return (i);
}

int	exec_echo(t_cmd command)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!command.av[1])
	{
		printf("\n");
		return (0);
	}
	i = norm_bs2(command, i, &flag);
	while (i < command.ac)
	{
		if (i != command.ac && i != flag + 1)
			printf(" ");
		printf("%s", command.av[i]);
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
