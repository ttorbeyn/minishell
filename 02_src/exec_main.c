/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:17:52 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/13 22:58:51 by vmusunga         ###   ########.fr       */
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

void	big_fat_init(t_cmd *cmd, t_data *data, int ac, char **av, char **env)
{
	int cmd_nb = 2;
	char *cmd0;
	char *cmd1;
	char *flag1;

	///MALLOCS
	cmd0 = malloc(sizeof(char) * 3 + 1);
	cmd1 = malloc(sizeof(char) * 3 + 1);
	flag1 = malloc(sizeof(char) * 2 + 1);
	data->cmd = malloc(sizeof(t_cmd) * cmd_nb + 1);

	///CMDS
	cmd0 = "env";
	cmd1 = "cat";
	flag1 = "-e";

	data->cmd_count = cmd_nb;

	/// T_CMD[0]
	data->cmd[0].cmd.ac = 1;
	data->cmd[0].cmd.cmd = ft_strdup(cmd0);
	data->cmd[0].cmd.av[0] = ft_strdup(cmd0);
	/// T_CMD[1]
	data->cmd[1].cmd.ac = 2;
	data->cmd[1].cmd.cmd = ft_strdup(cmd1);
	data->cmd[1].cmd.av[0] = ft_strdup(cmd1);
	data->cmd[1].cmd.av[1] = ft_strdup(flag1);

	envp_init(&data, env);

}

//INIT CMD_COUNT
int	main(int ac, char **av, char **env)
{
	t_data data;
	t_cmd cmd;
	int i;

	i = 0;
	if (ac < 2)
		return (1);
	cmd.ac = ac - 1;
	data_set(&data, &data.env, env);
	// cmd.av = malloc(sizeof(char*) * ac);
	// while (av[i+1])
	// {
	// 	cmd.av[i] = ft_strdup(av[i+1]);
	// 	i++;
	// }
	// envp_init(&data, env);
	// cmd.cmd = ft_strdup(av[1]);
	one_cmd(&cmd, &data);
	// i = -1;
	// while (cmd.av[++i])
	// 	printf("av%d:	%s\n", i, cmd.av[i]);
	// printf("cmd:	%s\n", cmd.cmd);
	return (0);
}
