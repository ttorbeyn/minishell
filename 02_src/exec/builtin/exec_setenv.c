/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_setenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:46:27 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 18:20:14 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

static int check_valid(char *av)
{
	int	i;

	i = 0;
	if (!ft_strchr(av, '='))
		return (1);
	while (ft_strncmp(av[i], "=", 1) && av[i])
	{
		if (!ft_isdigit((int)av[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
	set_env (or export) adds or modifies environement variables in envp
*/

int	exec_export(t_cmd command, t_data *data)
{
	int i;

	i = 0;
	if (check_valid(command.av[1]))
		return (1);
	while (command.av[1][i])
	{
		
	}
}