#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_isspace(char str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c, int i);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t len);

#endif
