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

int	ft_error(char *errmsg, int errnum)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(errmsg, 2);
	return (errnum);
}

void	ft_free_cmd(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->nb_cmd)
	{
		j = 0;
		while (data->cmds[i].av[j])
			free(data->cmds[i].av[j++]);
		if (data->cmds[i].in.path)
			free(data->cmds[i].in.path);
		if (data->cmds[i].in.doc->limit)
			free(data->cmds[i].in.doc->limit);
		if (data->cmds[i].out.path)
			free(data->cmds[i].out.path);
		if (data->cmds[i].out.doc->limit)
			free(data->cmds[i].out.doc->limit);
		if (data->cmds[i].av)
			free(data->cmds[i].av);
		i++;
	}
	free(data->cmds);
}

void	ft_free_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
		free(data->envp[i++]);
	free(data->envp);
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
		printf("___________________________________________________________\n");
		printf("CMD[%d]\n", i + 1);
		while (j < data->cmds[i].ac)
		{
			if (j == 0)
				printf("\tcmd\t:\t|%s|\n", data->cmds[i].av[j]);
			else
				printf("\tav[%d]\t:\t|%s|\n", j, data->cmds[i].av[j]);
			j++;
		}
		printf("REDIR IN\n");
		printf("\tpath\t:|%s|\n", data->cmds[i].in.path);
		printf("\tchmod\t:|%d|\n", data->cmds[i].in.chmod);
		printf("REDIR OUT\n");
		printf("\tpath\t:|%s|\n", data->cmds[i].out.path);
		printf("\tchmod\t:|%d|\n", data->cmds[i].out.chmod);
		printf("___________________________________________________________\n");
		i++;
	}
	return (0);
}
