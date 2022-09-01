#include "../01_include/minishell.h"

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
		lex(&data);
//		printf("coucou\n");
//		print_tok(&data.token);
//		printf("coucou2\n");
		parser(&data);
		int i = 0;
		int j;
		while (i < data.nb_cmd)
		{
			j = 0;
			while (j < data.cmds[i].ac)
			{
				printf("cmd[%d]|av[%d]\t:\t|%s|\n", i, j, data.cmds[i].av[j]);
				j++;
			}
			i++;
		}
//		parser(line, &data);
	}

	return (0);
}
