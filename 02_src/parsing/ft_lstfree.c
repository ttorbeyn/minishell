/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubert <ttorbeyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:08:11 by hubert            #+#    #+#             */
/*   Updated: 2021/01/15 19:08:45 by hubert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	if ((!lst) || (!(*lst)))
		return ;
	current = *lst;
	while (current != 0)
	{
		free(current->content);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*lst = 0;
}

void	ft_tokfree(t_token **tok)
{
	t_token	*current;
	t_token	*tmp;

	if ((!tok) || (!(*tok)))
		return ;
	current = *tok;
	while (current != 0)
	{
		if (current->content)
			free(current->content);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*tok = 0;
}

void	ft_herefree(t_here **here)
{
	t_here	*current;
	t_here	*tmp;

	if ((!here) || (!(*here)))
		return ;
	current = *here;
	while (current != 0)
	{
		if (current->limit)
			free(current->limit);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*here = 0;
}