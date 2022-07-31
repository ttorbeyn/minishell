#include "../../01_include/minishell.h"

int	double_quote_checker(char *str)
{
	int i;

	i = 0;
	while (str[i] != '"')

}

int	lex(t_data *data)
{
	int	i;
	t_cmd cmd;

	i = 0;
	while (data->line[i])
	{
		while (ft_isspace(data->line[i]))
			i++;
	}
}