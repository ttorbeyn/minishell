#include "../01_include/minishell.h"

void	print_tok(t_token **token)
{
	t_token	*first;
	int		len;
	int		i;

	len = 0;
	first = *token;
	while (first)
	{
		len++;
		first = first->next;
	}
	first = *token;
	i = 0;
	while (i < len)
	{
		printf("tok[%d] = |%s|\n", i, first->content);
		first = first->next;
		i++;
	}
}

int	print_cmd(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_cmd)
	{
		j = 0;
		printf("___________________________________________________________\n");
		printf("CMD[%d]\n", i + 1);
		while (j < data->cmds[i].ac)
		{
			if (j == 0)
				printf("\tcmd\t:\t|%s|\n", data->cmds[i].av[j]);
			else
				printf("\tav[%d]\t:\t|%s|\n", j, data->cmds[i].av[j]);
			j++;
		}
		printf("REDIR IN\n");
		printf("\tpath\t:|%s|\n", data->cmds[i].in.path);
		printf("\tchmod\t:|%d|\n", data->cmds[i].in.chmod);
		printf("REDIR OUT\n");
		printf("\tpath\t:|%s|\n", data->cmds[i].out.path);
		printf("\tchmod\t:|%d|\n", data->cmds[i].out.chmod);
		printf("___________________________________________________________\n");
		i++;
	}
	return (0);
}