/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:05:21 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:05:23 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

char	*get_line(void)
{
	char	*line;

	line = readline("Éshell : ");
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
