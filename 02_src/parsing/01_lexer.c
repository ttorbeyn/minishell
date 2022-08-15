#include "../../01_include/minishell.h"

int	lex(t_data *data)
{
	t_list *token;
	int i;

	i = 0;
	token = ft_strtok(data->line);
	while (token)
	{
		printf("content : %s\n", (char*)token->content);
		token = token->next;
	}
	return (0);
}