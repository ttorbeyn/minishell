/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:17:52 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/01 13:44:46 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/minishell.h"

void	print_lst(t_list **env)
{
	t_list *first;

	first = *env;
	int len = ft_lstsize(env);
	printf("lstsize:	%d\n", len);

	int i = 0;
	while (i < len)
	{
		printf("%s\n", (char*)first->content);
		// ft_putstr_fd(first->content, 1);
		first = first->next;
		i++;
	}
}


int	is_builtin(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->av[0], "cd", 2))
		return (1);
	if (!ft_strncmp(cmd->av[0], "echo", 4))
		return (exec_echo(cmd));
	if (!ft_strncmp(cmd->av[0], "exit", 4))
		return (3);
	if (!ft_strncmp(cmd->av[0], "env", 3))
		return (4);
	if (!ft_strncmp(cmd->av[0], "setenv", 6))
		return (5);
	if (!ft_strncmp(cmd->av[0], "unsetenv", 8))
		return (6);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data data;
	t_cmd *cmd;
	// int i;

	// i = -1;
	cmd = NULL;
	if (ac < 2)
		return (1);
	data_set(&data, &data.env, env);
	print_lst(&data.env);
	// cmd->av = &av[1];
	cmd->cmd = ft_strdup(av[1]);
	//is_builtin(&cmd);
	// while (av[++i])
	// 	printf("av:	%s\n", cmd->av[i]);
	printf("cmd:	%s\n", cmd->cmd);
	return (0);
}
