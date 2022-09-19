/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:18:37 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/19 12:56:29 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	is_space(char c)
{
	if (ft_strchr(" \n\t\v\f\r", c))
		return (1);
	return (0);
}

int	ft_error(char *errmsg, int errnum)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(errmsg, 2);
	g_exit = errnum;
	return (errnum);
}

void	ft_free_data(t_data *data)
{
	if (data->token)
		ft_tokfree(&data->token);
	ft_free_cmd(data);
}

void	ft_free_cmd(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_cmd)
	{
		j = 0;
		while (data->cmds[i].av[j])
			free(data->cmds[i].av[j++]);
		if (data->cmds[i].av)
			free(data->cmds[i].av);
		if (data->cmds[i].in.doc)
			ft_herefree(&data->cmds[i].in.doc);
		i++;
	}
	if (data->cmds)
		free(data->cmds);
}

void	ft_free_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
		free(data->envp[i++]);
	free(data->envp);
	if (data->env)
		ft_lstfree(&data->env);
}
