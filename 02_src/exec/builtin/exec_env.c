/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:36:41 by vic               #+#    #+#             */
/*   Updated: 2022/09/18 16:23:23 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../01_include/minishell.h"

void	print_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		ft_putendl_fd(envp[i], 1);
	return ;
}

void	update_envp(t_data *data)
{
	int		i;
	int		len;
	t_list	*tmp;

	tmp = data->env;
	len = ft_lstsize(&data->env);
	i = -1;
	if (data->envp)
	{
		while (data->envp[++i])
			free(data->envp[i]);
		free(data->envp);
	}
	data->envp = malloc(sizeof(char *) * len);
	if (!data->envp)
		return ;
	i = -1;
	while (++i < len && tmp->next)
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
		return_error("env: No arguments allowed", NULL, 1);
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
