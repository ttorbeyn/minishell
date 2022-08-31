/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:36:41 by vic               #+#    #+#             */
/*   Updated: 2022/08/31 18:45:50 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

int	exec_env(t_cmd command, t_data *data, t_pipes *p)
{
	t_list *tmp;

	tmp = data->env;
	if (command.ac > 1)
	{
		return_error("Error: Path not found", 0);
		return (1);
	}
	if (!tmp)
		return (1);
	while (tmp)
	{
		write(p->f_out, tmp->content, ft_strlen(tmp->content));
		write(p->f_out, "\n", 1);
		tmp = tmp->next;
	}
	return (0);
}