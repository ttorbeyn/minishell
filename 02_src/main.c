#include "../01_include/minishell.h"

//int	check_cmd()

//int parser(char *line, t_data *data)
//{
//	int	i;
//
//	i = 0;
//	while (line[i])
//	{
//		while (ft_isspace(line[i]))
//			i++;
////		check_cmd()
//	}
//}

void	print_lst(t_list **env)
{
	t_list *first;

	first = *env;
	int len = ft_lstsize(env);
	int i = 0;
	while (i < len)
	{
		printf("%p\n", first->content);
		first = first->next;
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*line;

	(void)ac;
	(void)av;
	line = "rien";
	data_set(&data, &data.env, env);
	print_lst(&data.env);
	signal(SIGQUIT, SIG_IGN);
	while (line)
	{
		line = readline("Éshell : ");
//		parser(line, &data);
		add_history(line);
	}
	return (0);
}
