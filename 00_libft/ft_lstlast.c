/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:18:33 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/07/31 22:01:58 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		ft_panic("Error : ft_lstlast\n");
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
