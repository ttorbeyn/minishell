/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:42:17 by vmusunga          #+#    #+#             */
/*   Updated: 2022/08/26 18:14:11 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	search_limit(char *input, char *limit)
{
	int	len;
	
	len = ft_strlen(input);
	if (!ft_strncmp(input, limit, len) && !input[len] && !limit[len])		//MIGHT BE LEN+1
			return (1);
	return (0);
}

int	found_limit(t_here **doc, char *input, int *fd)
{
	if ((*doc)->next == NULL)
	{
		free(input);
		close(*fd);
		*fd = open("heredoc", O_RDONLY, 0666);
		if (*fd < 0)
			return_error("Minishell: No such file or directory : heredoc", 1);
		if (unlink("heredoc"))
			ft_abort("Minishell: : Unlink failed", 255);
		return (1);
	}
	else
	{
		*doc = (*doc)->next;
		close(*fd);
		*fd = open("heredoc", O_TRUNC | O_WRONLY, 0666);
		if (*fd < 0)
			return_error("Minishell: heredoc", 1);
	}
	return (0);
}

int	open_heredoc(t_here *doc)
{
	int		fd;
	char	*input;

	fd = open("heredoc", O_CREAT | O_WRONLY, 0666);
	while(21)
	{
		input = readline(">");
		if (!input)
		{
			if (unlink("heredoc"))
				ft_abort("Minishell: : Unlink failed", 255);
				close(fd);
				exit(0);
		}
		if (*input && search_limit(input, doc->limit))
			found_limit(&doc, input, &fd);
		else
			ft_putendl_fd(input, fd);
		free(input);
	}
	return (0);
}