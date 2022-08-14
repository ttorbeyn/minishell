#include "../01_include/libft.h"

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*cpy;

	if (len > (int)ft_strlen(s1))
		return (NULL);
	i = 0;
	if (!(cpy = malloc(sizeof(const char) * (len + 1))))
		return (NULL);
	while (s1[i] && i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
