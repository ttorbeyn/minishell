#include "../../01_include/minishell.h"

void	data_set(t_data *data, t_list **env, char **env)
{
	int	i;

	(void)data;
	i = 0;
	while (env[i])
	{
		ft_lstadd_back(env, ft_lstnew(env[i]));
		i++;
	}
}