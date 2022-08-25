/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:17:52 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/25 18:47:33 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/minishell.h"

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

void	big_fat_init(t_data *data, char **env)
{
	int cmd_nb = 2;
	char *cmd0;
	// char *flag0;
	char *cmd1;
	char *flag1;

	///MALLOCS
	cmd0 = malloc(sizeof(char) * 3 + 1);
	cmd1 = malloc(sizeof(char) * 3 + 1);
	flag1 = malloc(sizeof(char) * 2 + 1);
	data->cmd = malloc(sizeof(t_cmd) * cmd_nb);
	data->cmd[0].av = malloc(sizeof(char*) * 1 + 1);
	data->cmd[1].av = malloc(sizeof(char*) * 2 + 1);

	///CMDS
	cmd0 = "pwd";
	// flag0 = "02_src/exec/builtin/exec_exit.c";
	cmd1 = "cat";
	flag1 = "-e";

	data->cmd_count = cmd_nb;

	/// T_CMD[0]
	data->cmd[0].ac = 1;
	data->cmd[0].cmd = ft_strdup(cmd0);
	data->cmd[0].av[0] = ft_strdup(cmd0);
	// data->cmd[0].av[1] = ft_strdup(flag0);
	
	/// T_CMD[1]
	data->cmd[1].ac = 2;
	data->cmd[1].cmd = ft_strdup(cmd1);
	data->cmd[1].av[0] = ft_strdup(cmd1);
	data->cmd[1].av[1] = ft_strdup(flag1);

	///CHECK
	// printf("cmd[0].cmd:	%s\n", data->cmd[0].cmd);
	// printf("cmd[0].av[0]:	%s\n", data->cmd[0].av[0]);
	// printf("cmd[1].cmd:	%s\n", data->cmd[1].cmd);
	// printf("cmd[1].av[0]:	%s\n", data->cmd[1].av[0]);
	// printf("cmd[1].av[1]:	%s\n", data->cmd[1].av[1]);

	envp_init(data, env);

}

//INIT CMD_COUNT
int	main(int ac, char **av, char **env)
{
	t_data data;
	int warning_samere;
	// int i;

	// i = 0;
	warning_samere = ft_strlen(av[0]);
	if (ac < 2)
		warning_samere++;

	data_set(&data, &data.env, env);
	big_fat_init(&data, env);
	cmd_switch(&data);
	return (0);
}
