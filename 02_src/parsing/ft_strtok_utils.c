#include "../../01_include/minishell.h"

int	is_space(char c)
{
	char *space;

	space = ft_strdup(" \n\t\v\f\r");
	if (ft_strchr(space, c))
		return (1);
	return (0);
}

int	is_delim(char c, char *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_separator(char *line)
{
	int i;

	i = 0;
	if (line[i] == '|')
		return (1);
	if ((line[i] == '>' && line[i + 1] == '>')
		|| (line[i] == '<' && line [i + 1] == '<'))
		return (2);
	if (line[i] == '<' || line[i] == '>')
		return (1);
	return (0);
}

int	check_quotes(int i, char *line)
{
	char quote_type;

	quote_type = line[i];
	while (line[i])
	{
		i++;
		if (line[i] == quote_type)
			return (i);
	}
	ft_panic("Quote not closed\n");
	return (0);
}