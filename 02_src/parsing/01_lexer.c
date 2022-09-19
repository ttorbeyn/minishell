/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:05:29 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:05:30 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	check_separator(t_token **token)
{
	t_token	*tmp;
	t_token	*new;
	char	*line;

	tmp = *token;
	if (tmp && tmp->type == PIPE)
		return (1);
	while (tmp)
	{
		if (tmp->type == PIPE && !tmp->next)
		{
			line = get_line("> ");
			new = ft_strtok(line);
			tmp->next = new;
		}
		if (tmp->type != WORD && (!tmp->next || tmp->next->type != WORD))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	count_cmd(t_token **token)
{
	int		count;
	t_token	*tmp;

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
	data->token = ft_strtok(data->line);
	if (!data->token)
		return (1);
	if (check_separator(&data->token))
	{
		ft_tokfree(&data->token);
		return (ft_error("separator error\n", 42));
	}
	data->nb_cmd = count_cmd(&data->token);
	return (0);
}
