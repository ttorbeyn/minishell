/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:36:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/07/31 18:10:19 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../01_include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if ((!s))
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
