/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:06:03 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:06:05 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	ft_free_str(char **begin, char **middle, char **end)
{
	if (*begin && *begin[0] != '\0')
		free(*begin);
	if (*middle && *middle[0] != '\0')
		free(*middle);
	if (*end && *end[0] != '\0')
		free(*end);
}

int	change_env_tok(t_data *data, t_token *token, int i)
{
	int		start;
	char	*begin;
	char	*var;
	char	*end;
	char	*env;

	end = NULL;
	begin = ft_strndup(token->content, i);
	i++;
	start = i;
	while (token->content[i] && token->content[i] != ' '
		&& token->content[i] != '$' && token->content[i] != '\''
		&& token->content[i] != '\"')
		i++;
	var = ft_strndup(&token->content[start], i - start);
	env = get_env_content(var, data->env);
	free(var);
	if (token->content[i])
		end = ft_strdup(&token->content[i]);
	free(token->content);
	token->content = triple_join(begin, env, end);
	i = start + ft_strlen(env) - 2;
	ft_free_str(&begin, &env, &end);
	return (i);
}

char	*change_env_str(char *quoted, t_data *data)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = ft_toknew(quoted, WORD);
	free(quoted);
	while (tmp->content[i])
	{
		if (tmp->content[i] == '$')
			i = change_env_tok(data, tmp, 0);
		i++;
	}
	quoted = ft_strdup(tmp->content);
	ft_tokfree(&tmp);
	return (quoted);
}

int	remove_quotes(t_token *token, int i, char quote, t_data *data)
{
	int		start;
	char	*begin;
	char	*quoted;
	char	*tmp;
	char	*end;

	end = NULL;
	begin = ft_strndup(token->content, i);
	start = ++i;
	while (token->content[i] != quote)
		i++;
	quoted = ft_strndup(&token->content[start], i - start);
	if (quote == '\"')
	{
		tmp = ft_strdup(quoted);
		free(quoted);
		quoted = change_env_str(tmp, data);
	}
	if (token->content[++i])
		end = ft_strdup(&token->content[i]);
	free(token->content);
	token->content = triple_join(begin, quoted, end);
	i = start + ft_strlen(quoted) - 2;
	ft_free_str(&begin, &quoted, &end);
	return (i);
}

t_token	*clean_tok(t_data *data)
{
	int		i;
	t_token	*head;

	head = data->token;
	while (data->token)
	{
		if (data->token->type == WORD)
		{
			i = 0;
			while (data->token->content && data->token->content[i])
			{
				if (data->token->content[i] == '\'')
					i = remove_quotes(data->token, i, '\'', data);
				if (data->token->content[i] == '\"')
					i = remove_quotes(data->token, i, '\"', data);
				if (data->token->content[i] == '$')
					i = change_env_tok(data, data->token, i);
				i++;
			}
		}
		data->token = data->token->next;
	}
	return (head);
}
