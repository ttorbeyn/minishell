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
//		printf("coucou3\n");

//		parser(line, &data);
	}
	return (0);
}
