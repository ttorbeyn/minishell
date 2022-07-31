#include "../../01_include/minishell.h"

void	data_set(t_data *data, t_list **envp, char **env)
{
	int	i;
	int	env_len;

	data->env = NULL;
	i = 0;
	env_len = 0;
	while (env[env_len])
		env_len++;
	printf("%d\n", env_len);
	while (i < env_len)
	{
		ft_lstadd_back(envp, ft_lstnew(env[i]));
		i++;
	}
}