/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:37:15 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/06 15:24:30 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/minishell.h"

void	envp_init(t_data *data, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (env[len])
		len++;
	data->envp = malloc(sizeof(char *) * len + 1);
	while (env[i])
	{
		data->envp[i] = ft_strdup(env[i]);
		i++;
	}
	return ;
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	data_set(&data, &data.env, env);
	signal(SIGQUIT, SIG_IGN);
	data.line = "rien";
	while (data.line)
	{
		data.line = get_line();
		if (lex(&data) || parser(&data))
			continue ;
//		print_cmd(&data);
		cmd_switch(&data);
	}
	return (0);
}
