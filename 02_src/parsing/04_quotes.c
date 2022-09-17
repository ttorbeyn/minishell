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

int	remove_simple_quotes(t_token *token, int i)
{
	int	start;

	token->content[i++] = '\0';
	start = i;
	while (token->content[i] && token->content[i] != '\'')
		i++;
	token->content[i++] = '\0';
	if (token->content[i])
		token->content = triple_join(token->content,
				&token->content[start], &token->content[i]);
	else
		token->content = double_join(token->content, &token->content[start]);
	return (i);
}

char	*replace_env(char *quote, t_data *data)
{
	int		i;
	int		start;
	char	*var;

	i = 0;
	while (quote[i])
	{
		if (quote[i] == '$')
		{
			quote[i++] = '\0';
			start = i;
			while (quote[i] && quote[i] != ' ' && quote[i] != '\''
				&& quote[i] != '$')
				i++;
			var = get_env_content(ft_strndup(&quote[start], i - start),
					data->env);
			if (quote[i])
				quote = triple_join(quote, var, &quote[i]);
			else
				quote = double_join(quote, var);
			i = start + ft_strlen(var) - 2;
		}
		i++;
	}
	free(var);
//	free(quote);
	return (quote);
}

int	remove_double_quotes(t_data *data, t_token *token, int i)
{
	int		start;
	char	*quote;
	char	*tmp;

	token->content[i++] = '\0';
	start = i;
	while (token->content[i] != '\"')
		i++;
	token->content[i++] = '\0';
	tmp = ft_strdup(&token->content[start]);
	quote = replace_env(ft_strdup(tmp), data);
//	if (token->content[i])
//		token->content = triple_join(token->content, quote, &token->content[i]);
//	else
//		token->content = double_join(token->content, quote);
	i = start + ft_strlen(quote) - 2;
	free(tmp);
	return (i);
}

int	change_env(t_data *data, t_token *token, int i)
{
	int		start;
	char	*quote;

	start = i;
	quote = replace_env(ft_strdup(&token->content[start]), data);
	token->content[i++] = '\0';
	token->content = double_join(token->content, quote);
	i = start + ft_strlen(quote) - 2;
	free(quote);
	return (i);
}

t_token	*remove_quotes(t_data *data)
{
	int		i;
	t_token	*head;

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
				if (data->token->content[i] == '$')
					i = change_env(data, data->token, i);
				i++;
			}
		}
		data->token = data->token->next;
	}
	return (head);
}
