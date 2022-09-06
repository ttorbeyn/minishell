/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:36:41 by vic               #+#    #+#             */
/*   Updated: 2022/09/06 16:28:33 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_env(t_cmd command, t_data *data, t_pipes *p)
{
	t_list	*tmp;

	tmp = data->env;
	if (command.ac > 1)
	{
		return_error("env: No arguments allowed", NULL, 0);
		return (1);
	}
	if (!tmp)
		return (1);
	while (tmp)
	{
		ft_putendl_fd(tmp->content, p->f_out);
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}
