/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:25:47 by amousaid          #+#    #+#             */
/*   Updated: 2024/02/09 00:47:39 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
// #include <sys/siginfo.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;
long				ft_atoi(const char *str);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
char				*ft_strdup(const char *s);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);
int					ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif
