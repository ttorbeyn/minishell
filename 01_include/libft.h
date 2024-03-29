/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:32:03 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/09/05 18:32:04 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		isdigit_check(char *s);
int		ft_isspace(char str);
int		ft_is_only_space_str(char *str);
char	*ft_itoa(int n);
int		ft_isascii(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, int len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_tolower(int c);
char	*ft_tolower_str(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstbeforelast(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstget(t_list *lst, int index);
int		ft_lstsize(t_list **lst);
void	ft_panic(char *str);

#endif
