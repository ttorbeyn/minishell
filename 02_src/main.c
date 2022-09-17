/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:37:15 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/17 17:30:33 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	
	(void)ac;
	(void)av;
	data_set(&data, &data.env, env);
	data.line = "rien";

	while (data.line)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		data.line = get_line();
		if (lex(&data) || parser(&data))
			continue ;
		cmd_switch(&data);
		ft_free_cmd(&data);
		// system("leaks minishell");
		//print_cmd(&data);
		ft_free_cmd(&data);

	}
	ft_free_env(&data);
	return (0);
}
