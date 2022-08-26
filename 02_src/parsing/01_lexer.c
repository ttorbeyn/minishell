#include "../../01_include/minishell.h"

int	check_separator(t_token **token)
{
	t_token *tmp;

	tmp = *token;
	if (tmp && tmp->type != WORD)
		return (1);
	while (tmp)
	{
		if (tmp->type != WORD && (!tmp->next || tmp->next->type != WORD))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	count_cmd(t_token **token)
{
	int	count;
	t_token *tmp;

	tmp = *token;
	count = 1;
	while (tmp)
	{
		if (tmp->type == PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	lex(t_data *data)
{
	int i;
	t_token *tmp;

	i = 0;
	data->token = ft_strtok(data->line);
	if (!data->token)
		return (1);
	if (check_separator(&data->token))
		return (ft_error("Separator error\n"));
	data->nb_cmd = count_cmd(&data->token);
	tmp = data->token;
	while (tmp)
	{
		printf("content[%d] : %s\n", i, (char*)tmp->content);
		printf("type[%d] : %d\n", i, tmp->type);
		tmp = tmp->next;
		i++;
	}
	printf("cmd_count : [%d]\n", data->nb_cmd);
	return (0);
}