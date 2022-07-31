#include "../01_include/minishell.h"

//int	check_cmd()

int parser(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
//		check_cmd()
	}
}


int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*line;

	(void)ac;
	(void)av;
	line = "rien";
	data_set
	data.envp = env;
	signal(SIGQUIT, SIG_IGN);
	while (line)
	{
		line = readline("Éshell : ");
		parser(line, &data);
		add_history(line);
		int i = 0;
		while (data.envp[i])
			printf("%s\n", data.envp[i++]);
	}
	return (0);
}
