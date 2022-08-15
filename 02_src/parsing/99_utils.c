#include "../../01_include/minishell.h"

int		ft_error(char *error)
{
	ft_putstr_fd("Error: ",2);
	ft_putstr_fd(error,2);
	return (1);
}

void	print_lst(t_list **env)
{
	t_list *first;

	first = *env;
	int len = ft_lstsize(env);
	int i = 0;
	while (i < len)
	{
		printf("%p\n", first->content);
		first = first->next;
		i++;
	}
}