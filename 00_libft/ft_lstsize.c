/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:19:01 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/01/05 01:05:47 by hubert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

int	ft_lstsize(t_list **lst)
{
	int		i;
	t_list	*first;

	first = *lst;
	i = 0;
	while (first)
	{
		first = first->next;
		i++;
	}
	return (i);
}
