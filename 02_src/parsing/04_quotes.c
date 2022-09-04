#include "../../01_include/minishell.h"

char	*triple_join(char *s1, char *s2, char *s3)
{
	char *new;

	new = NULL;
	if (s1 && s2 && s3)
	{
		new = ft_strjoin(s1, s2);
		new = ft_strjoin(new, s3);
	}
	if (!s1 && s2 && s3)
		new = ft_strjoin(s2, s3);
	if (s1 && !s2 && s3)
		new = ft_strjoin(s1, s3);
	if (s1 && s2 && !s3)
		new = ft_strjoin(s1, s2);
	if (!s1 && !s2)
		return (s3);
	if (!s1 && !s3)
		return (s2);
	if (!s2 && !s3)
		return (s1);
	return (new);
}

int	remove_simple_quotes(t_token *token, int i)
{
	int	start;

	token->content[i] = '\0';
	start = ++i;
	while (token->content[i] && token->content[i] != '\'')
		i++;
	token->content[i] = '\0';
	token->content = triple_join(token->content, &token->content[start], &token->content[i + 1]);
	return (i);
}

int	remove_double_quotes(t_data *data, t_token *token, int i)
{
	int	start;
	char *env;

	token->content[i] = '\0';
	start = ++i;
	while (token->content[i] && token->content[i] != '\"')
	{
		if (token->content[i] == '$')
		{
			start = ++i;
			while (!is_space(token->content[i]) && token->content[i] != '\"')
				i++;
			env = get_env_content(ft_strndup(&token->content[start], i - start), data->env);
			token->content = triple_join(token->content, env, &token->content[i]);
			i = -1;
		}
		i++;
	}
	token->content[i] = '\0';
	token->content = triple_join(token->content, &token->content[start], &token->content[i + 1]);
	return (i);
}

t_token *remove_quotes(t_data *data)
{
	int i;
	t_token *head;

	head = data->token;
	while (data->token)
	{
		if (data->token->type == WORD)
		{
			i = 0;
			while (data->token->content[i])
			{
				if (data->token->content[i] == '\'')
					i = remove_simple_quotes(data->token, i);
				if (data->token->content[i] == '\"')
					i = remove_double_quotes(data, data->token, i);
				i++;
			}
		}
		data->token = data->token->next;
	}
	return (head);
}