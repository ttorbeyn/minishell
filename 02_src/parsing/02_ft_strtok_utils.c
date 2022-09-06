/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_strtok_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:05:50 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:05:51 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

t_token	*ft_toknew(char *content, int type)
{
	t_token	*new;

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
	t_token	*current;

	current = *token;
	if (token == NULL || new == NULL)
		ft_panic("Error : malloc ft_tokadd_back\n");
	if (*token == NULL)
		*token = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
		new->next = 0;
	}
}

int	is_separator(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '|')
		return (1);
	if ((line[i] == '>' && line[i + 1] == '>')
		|| (line[i] == '<' && line [i + 1] == '<'))
		return (2);
	if (line[i] == '<' || line[i] == '>')
		return (1);
	return (0);
}

int	check_quotes(int i, char *line)
{
	char	quote_type;

	quote_type = line[i];
	while (line[i])
	{
		i++;
		if (line[i] == quote_type)
			return (i);
	}
	return (ft_error("Quote not closed\n", -1));
}
