/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_strtok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:05:44 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:05:46 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	token_type(char *token)
{
	int	i;

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

char	*create_token(t_token **token, char *begin, char *end)
{
	char	*bgn;
	char	*tmp;
	int		len;
	int		type;

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
//	free(tmp);
	return (begin);
}

int	tok_sep(t_token **token, char **tmp, char *line, int i)
{
	*tmp = create_token(token, *tmp, &line[i]);
	i += is_separator(&line[i]);
	if (line[i] && ft_strchr("|<>", line[i]))
		return (ft_error("separator error\n", -1));
	*tmp = create_token(token, *tmp, &line[i]);
	return (i);
}

int	init_token(char **line, char **tmp, t_token **token)
{
	char *line_tmp;

	line_tmp = *line;
	*token = NULL;
	if (!*line)
		return (0);
	*line = ft_strtrim(line_tmp, " ");
	free(line_tmp);
	if (!*line)
		return (ft_error("trim error\n", 1));
	*tmp = *line;
	return (0);
}

t_token	*ft_strtok(char *line)
{
	int		i;
	char	*tmp;
	t_token	*token;

	i = init_token(&line, &tmp, &token);
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			i = check_quotes(i, line);
		if (is_separator(&line[i]) && line[i])
			i = tok_sep(&token, &tmp, line, i);
		else if (is_space(line[i]))
		{
			tmp = create_token(&token, tmp, &line[i]);
			while (is_space(line[i]) && line[i])
				tmp = &line[++i];
		}
		else
			i++;
	}
	if (i == -1)
		return (NULL);
	create_token(&token, tmp, &line[i]);
	free(line);
	return (token);
}
