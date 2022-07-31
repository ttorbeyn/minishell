#include "../../01_include/minishell.h"

void	data_set(t_data *data, t_list **env, char **env)
{
	int	i;
	int	env_len;

	(void)data;
	data->env = NULL;
//	(void)envp;
	i = 0;
	env_len = 0;
	while (env[env_len])
		env_len++;
	printf("%d\n", env_len);
	while (i < env_len)
	{
		ft_lstadd_back(env, ft_lstnew(env[i]));
		i++;
	}
}