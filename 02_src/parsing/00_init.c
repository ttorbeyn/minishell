#include "../../01_include/minishell.h"

char	*get_line(t_data *data)
{
	char	*line;

	(void)data;
	line = readline("Éshell : ");
	add_history(line);
	return(line);
}

void	data_set(t_data *data, t_list **envp, char **env)
{
	int	i;
	int	env_len;

	data->double_quotes = 0;
	data->simple_quotes = 0;
	data->env = NULL;
	i = 0;
	env_len = 0;
	while (env[env_len])
		env_len++;
	while (i < env_len)
	{
		ft_lstadd_back(envp, ft_lstnew(env[i]));
		i++;
	}
}
