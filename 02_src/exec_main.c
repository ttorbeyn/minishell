/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:17:52 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/13 14:07:50 by vmusunga         ###   ########.fr       */
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
		printf("%d:	%s\n", i, (char*)first->content);
		// ft_putstr_fd(first->content, 1);
		first = first->next;
		i++;
	}
}

int	is_builtin(t_cmd *cmd, t_data *data)
{
	if (!ft_strncmp(cmd->av[0], "cd", 2))
		return (exec_cd(cmd, data));
	if (!ft_strncmp(cmd->av[0], "echo", 4))
		return (exec_echo(cmd));
	if (!ft_strncmp(cmd->av[0], "exit", 4))
		return (3);
	if (!ft_strncmp(cmd->av[0], "env", 3))
		return (exec_env(cmd, data));
	if (!ft_strncmp(cmd->av[0], "pwd", 3))
		return (exec_pwd(data));
	if (!ft_strncmp(cmd->av[0], "export", 6))
		return (exec_export(cmd, data));
	if (!ft_strncmp(cmd->av[0], "unset", 5))
		return (exec_unset(cmd, data));
	return (0);
}

void	envp_init(t_data *data, char **env)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (env[len])
		len++;
	data->envp = malloc(sizeof(char*) * len +1);
	while (env[i])
	{
		data->envp[i] = ft_strdup(env[i]);
		i++;
	}
	return;
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
	envp_init(&data, env);
	cmd.cmd = ft_strdup(av[1]);
	is_builtin(&cmd, &data);
	one_cmd(&cmd, &data);
	// i = -1;
	// while (cmd.av[++i])
	// 	printf("av%d:	%s\n", i, cmd.av[i]);
	// printf("cmd:	%s\n", cmd.cmd);
	return (0);
}
