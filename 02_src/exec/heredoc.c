/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:42:17 by vmusunga          #+#    #+#             */
/*   Updated: 2022/09/19 11:38:36 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../01_include/minishell.h"

int	search_limit(char *input, char *limit)
{
	int		len;

	len = ft_strlen(input);
	if (!ft_strncmp(input, limit, len) && !input[len] && !limit[len])
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
			return_error("Error : No such file or directory : heredoc",
				NULL, 1);
		if (unlink("heredoc"))
			ft_abort("Error : Unlink failed");
		return (1);
	}
	else
	{
		*doc = (*doc)->next;
		close(*fd);
		*fd = open("heredoc", O_TRUNC | O_WRONLY, 0666);
		if (*fd < 0)
			return_error("Error : heredoc", NULL, 1);
	}
	return (0);
}

int	open_heredoc(t_here *doc)
{
	int		fd;
	char	*input;

	fd = open("heredoc", O_CREAT | O_WRONLY, 0666);
	signal(SIGINT, SIG_DFL);
	while (21)
	{
		input = readline("> ");
		if (!input)
		{
			if (unlink("heredoc"))
				ft_abort("Error : Unlink failed");
			close(fd);
			exit(0);
		}
		if (*input && search_limit(input, doc->limit))
		{
			if (found_limit(&doc, input, &fd))
				return (fd);
		}
		else
			ft_putendl_fd(input, fd);
		free(input);
	}
	return (0);
}
