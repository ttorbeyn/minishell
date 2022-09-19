/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:34:28 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/19 14:34:34 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

t_token	*delete_tok_null_begin(t_token *token)
{
	t_token	*head;
	t_token	*tmp;

	head = token;
	while (head && head->content == NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (head);
}

t_token	*delete_tok_null(t_data *data)
{
	t_token	*head;
	t_token	*tmp;

	head = delete_tok_null_begin(data->token);
	if (!head)
		return (NULL);
	data->token = head;
	tmp = data->token->next;
	while (tmp)
	{
		if (tmp->content == NULL)
		{
			data->token->next = tmp->next;
			free(tmp);
		}
		if (data->token->next)
		{
			data->token = data->token->next;
			tmp = data->token->next;
		}
		else
			break ;
	}
	return (head);
}
