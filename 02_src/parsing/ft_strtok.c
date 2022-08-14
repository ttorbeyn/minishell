#include "../../01_include/minishell.h"

int	is_space(char c)
{
	char *space;

	space = ft_strdup(" \n\t\v\f\r");
	if (ft_strchr(space, c))
		return (1);
	return (0);
}

int	is_delim(char c, char *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_separator(char *line)
{
	int i;

	i = 0;
	if (line[i] == '|')
		return (1);
	if ((line[i] == '>' && line[i + 1] == '>') || (line[i] == '<' && line [i + 1] == '<'))
		return (2);
	if (line[i] == '<' || line[i] == '>')
		return (1);
	return (0);
}

int	check_quotes(int i, char *line)
{
	char quote_type;

	quote_type = line[i];
	while (line[i])
	{
		i++;
		if (line[i] == quote_type)
			return (i);
	}
	ft_panic("Quote not closed\n");
	return (0);
}

char *create_token(t_list **token, char *begin, char *end)
{
	char *bgn;
	int len;

	len = 0;
//	printf("begin : %p\n", &begin[3]);
//	printf("end : %p\n", &end);
	bgn = begin;
	while (*begin && begin != end)
	{
		begin++;
		len++;
	}
	printf("len : %d\n", len);
	if (len)
		ft_lstadd_back(token, ft_lstnew(ft_strndup(bgn, len)));
	return (begin);
}

t_list	*ft_strtok(char *line)
{
	int	i;
	char	*tmp;
	t_list *token;

	token = NULL;
	i = 0;
	line = ft_strtrim(line, " ");
	tmp = line;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			i = check_quotes(i, line);
		if (is_separator(&line[i]) && line[i])
		{
			tmp = create_token(&token, tmp, &line[i]);
			i += is_separator(&line[i]);
			tmp = create_token(&token, tmp, &line[i]);
		}
		if (is_space(line[i]))
		{
			tmp = create_token(&token, tmp, &line[i]);
			while (is_space(line[i]) && line[i])
				tmp = &line[++i];
		}
		else
			i++;
	}
	create_token(&token, tmp, &line[i]);
	return (token);
}
