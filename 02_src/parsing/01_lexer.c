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
	t_token *tmp;
	int	count;

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
	t_token *token;
	int i;
	int cmd_count;

	i = 0;
	token = ft_strtok(data->line);
	if (!token)
		return (1);
	if (check_separator(&token))
		return (ft_error("Separator error\n"));
	cmd_count = count_cmd(&token);
	while (token)
	{
		printf("content[%d] : %s\n", i, (char*)token->content);
		printf("type[%d] : %d\n", i, token->type);
		token = token->next;
		i++;
	}
	printf("cmd_count : [%d]\n", cmd_count);

	return (0);
}