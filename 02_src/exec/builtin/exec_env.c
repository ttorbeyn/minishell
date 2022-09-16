/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:36:41 by vic               #+#    #+#             */
/*   Updated: 2022/09/15 16:11:20 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

void	update_envp(t_data *data)
{
	int		i;
	int		len;
	t_list	*tmp;

	len = ft_lstsize(&data->env);
	tmp = data->env;
	i = 0;
	if (data->envp)
		free(data->envp);
	data->envp = malloc(sizeof(char *) * len);
	if (!data->envp)
	{
		return_error("env malloc error", NULL, 2);
		return ;
	}
	i = -1;
	while (++i < len)
	{
		data->envp[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
}

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
