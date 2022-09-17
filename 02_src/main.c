/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:37:15 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/16 23:58:25 by vmusunga         ###   ########.fr       */
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
	g_exit = 0;
	while (data.line)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		data.line = get_line();
		if (lex(&data) || parser(&data))
			continue ;
		print_cmd(&data);
		cmd_switch(&data);
		ft_free_cmd(&data);
//		printf("%d\n", g_exit);
	}
	ft_free_env(&data);
	return (0);
}
