/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:18:37 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:18:40 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	is_space(char c)
{
	char	*space;

	space = ft_strdup(" \n\t\v\f\r");
	if (ft_strchr(space, c))
		return (1);
	return (0);
}

int	ft_error(char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error, 2);
	return (1);
}

void	print_tok(t_token **token)
{
	t_token	*first;
	int		len;
	int		i;

	len = 0;
	first = *token;
	while (first)
	{
		len++;
		first = first->next;
	}
	first = *token;
	i = 0;
	while (i < len)
	{
		printf("tok[%d] = |%s|\n", i, first->content);
		first = first->next;
		i++;
	}
}

int	print_cmd(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_cmd)
	{
		j = 0;
		while (j < data->cmds[i].ac)
		{
			printf("cmd[%d]|av[%d]\t:\t|%s|\n", i, j, data->cmds[i].av[j]);
			j++;
		}
		i++;
	}
	return (0);
}
