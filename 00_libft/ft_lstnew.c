/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:18:50 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/07/31 22:01:55 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*begin;

	begin = malloc(sizeof(t_list));
	if (begin == NULL)
		ft_panic("Error : ft_lstnew\n");
	begin->content = content;
	begin->next = NULL;
	return (begin);
}
