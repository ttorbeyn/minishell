#include "../../01_include/minishell.h"

t_token *ft_toknew(char* content, int type)
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		ft_panic("Error : malloc ft_toknew\n");
	new->content = content;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	ft_tokadd_back(t_token **token, t_token *new)
{
	t_token *current;

	current = *token;
	if (token == NULL || new == NULL)
		return ;
	if (*token == NULL)
		*token = new;
	else
	{
		while (current->next)
			current = current->next;
//		if (current->next)
		current->next = new;
		new->next = 0;
	}
}

int	token_type(char *token)
{
	int i;

	i = 0;
	if (ft_strlen(token) == 1)
	{
		if (token[i] == '|')
			return (PIPE);
		if (token[i] == '>')
			return (GREAT);
		if (token[i] == '<')
			return (LESS);
	}
	if (ft_strlen(token) == 2)
	{
		if (token[i] == '>')
			return (DGREAT);
		if (token[i] == '<')
			return (DLESS);
	}
	return (WORD);
}

char *create_token(t_token **token, char *begin, char *end)
{
	char *bgn;
	int len;
	char *tmp;
	int type;

	len = 0;
	bgn = begin;
	while (*begin && begin != end)
	{
		begin++;
		len++;
	}
	tmp = ft_strndup(bgn, len);
	type = token_type(tmp);
	if (len)
		ft_tokadd_back(token, ft_toknew(tmp, type));
	return (begin);
}

t_token	*ft_strtok(char *line)
{
	int	i;
	char	*tmp;
	t_token *token;

	token = NULL;
	i = 0;
	line = ft_strtrim(line, " ");
	tmp = line;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			i = check_quotes(i, line);
			if (i == -1)
				return (NULL);
		}
		if (is_separator(&line[i]) && line[i])
		{
			tmp = create_token(&token, tmp, &line[i]);
			i += is_separator(&line[i]);
			if (line[i] && ft_strchr("|<>", line[i]))
			{
				ft_error("Error separator\n");
				return(NULL);
			}
			tmp = create_token(&token, tmp, &line[i]);
			continue ;
		}
		if (is_space(line[i]))
		{
			tmp = create_token(&token, tmp, &line[i]);
			while (is_space(line[i]) && line[i])
				tmp = &line[++i];
			continue ;
		}
		else
			i++;
	}
	create_token(&token, tmp, &line[i]);
	return (token);
}
