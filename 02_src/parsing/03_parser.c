#include "../../01_include/minishell.h"

void get_redirection(t_data *data)
{
	t_token *tmp;


	tmp = data->token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			tmp = tmp->next;
		tmp = tmp->next;
	}
}

t_token *count_arg(t_token *tmp, t_cmd *cmd)
{
//	int count;
//	t_token *tmp;

//	tmp = token;
//	count = 0;
//	printf("count : %d", count);

	if (!tmp)
		return (0);
	while (tmp && tmp->type == WORD)
	{
		cmd->ac++;
		tmp = tmp->next;
	}
	if (tmp && tmp->type == PIPE)
	{
		tmp = tmp->next;
//		print_tok(&tmp);

		return (tmp);
	}
//	print_tok(&tmp);

	return (tmp);
}

t_token *make_av(t_token *token, t_cmd *cmd)
{
//	char **av;

//	av = NULL;
//	printf("coucou3\n");
	token = count_arg(token, cmd);
//	print_tok(&token);
//	av = malloc(sizeof(char*) * args)
	return (token);
}

int	parser(t_data *data)
{
	t_token *tmp;
	int i;

	i = 0;
	tmp = data->token;
	data->cmds = malloc(sizeof(t_cmd) * data->nb_cmd);
	printf("nb of cmd : %d\n", data->nb_cmd);
	while (i < data->nb_cmd)
	{
//		printf("coucou\n");
		print_tok(&tmp);

		tmp = make_av(tmp, &data->cmds[i]);
		printf("ac[%d] : %d\n", i, data->cmds[i].ac);
//		printf("coucou2\n");

		i++;
	}

	return (0);
}