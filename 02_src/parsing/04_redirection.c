/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:06:11 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/16 23:20:24 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

t_here	*ft_herenew(char *limit)
{
	t_here	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		ft_panic("Error : malloc ft_toknew\n");
	new->limit = limit;
	new->next = NULL;
	return (new);
}

void	ft_hereadd_back(t_here **token, t_here *new)
{
	t_here	*current;

	current = *token;
	if (token == NULL || new == NULL)
		return ;
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

t_token	*cmd_redirection(t_token *token, t_redir *redir, int chmod)
{
	int	fd;

	token = token->next;
	redir->path = token->content;
	redir->chmod = chmod;
	fd = open(token->content, chmod, 0644);
	close(fd);
	token = token->next;
	return (token);
}

t_token	*redirection(t_token *token, t_cmd *cmd)
{
	if (token->type == GREAT)
		token = cmd_redirection(token, &cmd->out,
				(O_CREAT | O_TRUNC | O_RDWR));
	else if (token->type == LESS)
		token = cmd_redirection(token, &cmd->in, (O_RDONLY));
	else if (token->type == DGREAT)
		token = cmd_redirection(token, &cmd->out,
				(O_CREAT | O_APPEND | O_RDWR));
	else if (token->type == DLESS)
	{
		token = token->next;
		ft_hereadd_back(&cmd->in.doc, ft_herenew(token->content));
	}
	return (token);
}
