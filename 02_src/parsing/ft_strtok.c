#include "../../01_include/minishell.h"



char *create_token(t_list **token, char *begin, char *end)
{
	char *bgn;
	int len;

	len = 0;
	bgn = begin;
	while (*begin && begin != end)
	{
		begin++;
		len++;
	}
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
			if (line[i] && ft_strchr("|<>", line[i]))
				ft_panic("Error separator");
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
