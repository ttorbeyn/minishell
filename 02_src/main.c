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

int	print_cmd(t_data *data)
{
	int i = 0;
	int j;
	while (i < data->nb_cmd)
	{
		j = 0;
		while (j < data->cmds[i].ac)
		{
			printf("cmd[%d]|av[%d]\t:\t|%s|\n", i, j, data->cmds[i].av[j]);
			j++;
		}
		i++;
	}
	return (0);
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
		data.line = get_line(&data);
		if (lex(&data) || parser(&data))
			continue;
		print_cmd(&data);
//		cmd_switch(&data);
//		parser(line, &data);
	}

	return (0);
}
