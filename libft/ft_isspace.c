#include "libft.h"

int	ft_isspace(char str)
{
	int	i;

	i = 0;
	if (str == ' ' || str == '\t' || str == '\n' || str == '\v'
		   || str == '\f' || str == '\r')
		return (1);
	return (0);
}
