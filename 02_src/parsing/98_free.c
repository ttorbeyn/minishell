/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   98_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:01:51 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/18 23:02:05 by ttorbeyn         ###   ########.fr       */
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
