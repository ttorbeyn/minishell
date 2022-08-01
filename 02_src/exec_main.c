/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:17:52 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/01 16:02:19 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/minishell.h"

void	print_lst(t_list **env)
{
	t_list *first;

	first = *env;
	int len = ft_lstsize(env);
	// printf("lstsize:	%d\n", len);

	int i = 0;
	while (i < len)
	{
		printf("%s\n", (char*)first->content);
		// ft_putstr_fd(first->content, 1);
		first = first->next;
		i++;
	}
}


int	is_builtin(t_cmd *cmd, t_data *data)
{
	if (!ft_strncmp(cmd->av[0], "cd", 2))
		return (1);
	if (!ft_strncmp(cmd->av[0], "echo", 4))
		return (exec_echo(cmd));
	if (!ft_strncmp(cmd->av[0], "exit", 4))
		return (3);
	if (!ft_strncmp(cmd->av[0], "env", 3))
		return (exec_env(cmd, data));
	if (!ft_strncmp(cmd->av[0], "export", 6))
		return (exec_export(cmd, data));
	if (!ft_strncmp(cmd->av[0], "unsetenv", 8))
		return (6);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data data;
	t_cmd cmd;
	// int len_env;
	int i;

	i = 0;
	// len_env = ft_lstsize(&data.env);
	if (ac < 2)
		return (1);
	cmd.ac = ac - 1;
	data_set(&data, &data.env, env);
	cmd.av = malloc(sizeof(char*) * ac);
	// print_lst(&data.env);
	while (av[i+1])
	{
		cmd.av[i] = ft_strdup(av[i+1]);
		i++;
	}
	cmd.cmd = ft_strdup(av[1]);
	is_builtin(&cmd, &data);
	i = -1;
	// while (cmd.av[++i])
	// 	printf("av%d:	%s\n", i, cmd.av[i]);
	// printf("cmd:	%s\n", cmd.cmd);
	return (0);
}
