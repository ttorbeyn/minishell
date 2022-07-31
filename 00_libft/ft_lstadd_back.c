/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:47:16 by ttorbeyn          #+#    #+#             */
/*   Updated: 2021/12/30 21:23:26 by hubert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *current;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = ft_lstlast(*lst);
		if (current->next)
			current->next = new;
		new->next = 0;
	}
}