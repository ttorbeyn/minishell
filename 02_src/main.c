/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:37:15 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/18 19:12:29 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	
	(void)ac;
	(void)av;
	data_set(&data, &data.env, env);
//	data.line = "rien";
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		data.line = get_line();
		if (lex(&data))
			continue ;
		if (parser(&data))
			continue ;
		print_cmd(&data);
		cmd_switch(&data);
//		printf("%d\n", g_exit);
		ft_free_data(&data);
		system("leaks minishell");
	}
//	ft_free_env(&data);
	return (0);
}
