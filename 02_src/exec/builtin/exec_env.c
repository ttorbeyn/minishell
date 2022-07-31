/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:36:41 by vic               #+#    #+#             */
/*   Updated: 2022/07/31 20:15:14 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_env(t_cmd command, t_data *data)
{
	t_list *tmp;

	tmp = data->env;
	if (command.ac > 2)
	{
		ft_putendl_fd("Error: Too many arguments", 2);
		return (1);
	}
	if (!tmp)
		return (1);
	while (tmp)
	{
		ft_putstr_fd(tmp->content, 1);
		write (1, "\n", 1);
		tmp = tmp->next;
	}
	return (0);
}