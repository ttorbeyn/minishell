/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:37:15 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/19 16:41:44 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	data_set(&data, &data.env, env);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		data.line = get_line();
		if (lex(&data) || parser(&data))
			continue ;
		// print_cmd(&data);
		cmd_switch(&data);
		ft_free_data(&data);
	}
	ft_free_env(&data);
	return (0);
}
