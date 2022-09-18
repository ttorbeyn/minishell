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

//int	check_env(char *quoted, t_data *data)
//{
//	int i;
//
//	i = 0;
//	while (quoted[i])
//	{
//		if (quoted[i] == '$')
//			return (i);
//		i++;
//	}
//	return (str);
//}
//
//int	change_env(char *quoted, t_data *data)
//{
//	int		start;
//	char	*begin;
//	char	*quoted;
//	char 	*end;
//
//	end = NULL;
//	begin = ft_strndup(token->content, i);
//	i++;
//	start = i;
//	while (token->content[i] && token->content[i] != ' ')
//		i++;
//	quoted = ft_strndup(&token->content[start], i - start);
//	quoted = get_env_content(quoted, data->env);
//	i++;
//	if (token->content[i])
//		end = ft_strdup(&token->content[i]);
//	free(token->content);
//	token->content = triple_join(begin, quoted, end);
//	i = start + ft_strlen(quoted) - 2;
//	free(begin);
//	free(quoted);
//	if (end)
//		free(end);
//	return (i);
//}

int	change_env_tok(t_data *data, t_token *token, int i)
{
	int		start;
	char	*begin;
	char	*quoted;
	char 	*end;
	char	*env;

	end = NULL;
	begin = ft_strndup(token->content, i);
	i++;
	start = i;
	while (token->content[i] && token->content[i] != ' ' && token->content[i] != '$' && token->content[i] != '\'' && token->content[i] != '\"')
		i++;
	quoted = ft_strndup(&token->content[start], i - start);
	env = get_env_content(quoted, data->env);
	free(quoted);
	if (token->content[i])
		end = ft_strdup(&token->content[i]);
	free(token->content);
	token->content = triple_join(begin, env, end);
	i = start + ft_strlen(env) - 2;
	printf("tok : %s\n", token->content);
	printf("i : %d\n", i);
	if (begin)
		free(begin);
	if (env)
		free(env);
	if (end)
		free(end);
	return (i);
}

int	remove_quotes(t_token *token, int i, char quote, t_data *data)
{
	int		start;
	char	*begin;
	char	*quoted;
	char 	*end;
	t_token *tmp;

	end = NULL;
	begin = ft_strndup(token->content, i);
	i++;
	start = i;
	while (token->content[i] != quote)
		i++;
	quoted = ft_strndup(&token->content[start], i - start);
	if (quote == '\"')
	{
		tmp = ft_toknew(quoted, WORD);
		change_env_tok(data, tmp, 0);
		free(quoted);
		quoted = ft_strdup(tmp->content);
		free(tmp);
	}
	(void)data;
	i++;
	if (token->content[i])
		end = ft_strdup(&token->content[i]);
	free(token->content);
	token->content = triple_join(begin, quoted, end);
	i = start + ft_strlen(quoted) - 2;
	free(begin);
	free(quoted);
	if (end)
		free(end);
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
			while (data->token->content[i])
			{
				if (data->token->content[i] == '\'')
					i = remove_quotes(data->token, i, '\'', data);
//				if (data->token->content[i] == '\"')
//				{
//					i = remove_quotes(data->token, i, '\"', data);
////					i = change_env_tok(data, data->token, i);
//				}
				if (data->token->content[i] == '$')
					i = change_env_tok(data, data->token, i);
				i++;
			}
		}
		data->token = data->token->next;
	}
	return (head);
}