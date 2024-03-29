/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:05:21 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/19 19:46:07 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	envp_init(t_data *data, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (env[len])
		len++;
	data->envp = malloc(sizeof(char *) * len + 1);
	if (!data->envp)
		return ;
	while (env[i])
	{
		data->envp[i] = ft_strdup(env[i]);
		i++;
	}
	data->envp[i] = NULL;
	return ;
}

char	*get_line(char *str)
{
	char	*line;

	line = readline(str);
	if (ft_strlen(line) && !ft_is_only_space_str(line))
		add_history(line);
	return (line);
}

void	data_set(t_data *data, t_list **envp, char **env)
{
	int	i;
	int	env_len;

	data->env = NULL;
	i = 0;
	env_len = 0;
	while (env[env_len])
		env_len++;
	while (i < env_len)
	{
		ft_lstadd_back(envp, ft_lstnew(env[i]));
		i++;
	}
	envp_init(data, env);
}
