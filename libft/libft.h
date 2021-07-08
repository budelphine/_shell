/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:39:06 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/03 17:36:55 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 32

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);

void				*ft_calloc(size_t count, size_t size);

int					ft_memcmp(void *src, void *dest, size_t count);
void				*ft_memccpy(void *dest, void *src, int ch, size_t count);
void				*ft_memchr(void *src, int c, size_t n);
void				*ft_memcpy(void *dest, void *src, size_t count);
void				*ft_memmove(void *dest, void *src, size_t count);
void				*ft_memset(void *dest, int ch, size_t count);

char				*ft_strdup(char *str);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlcpy(char *dest, char *src, size_t size);

char				*ft_strjoin(char *str1, char *str2);
char				*ft_substr(char *str, unsigned int start, size_t len);
char				*ft_strtrim(char *str, char *set);
char				**ft_split(char *str, char c);
char				*ft_strmapi(char *str, char (*f)(unsigned int, char));

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
								void (*del)(void *));

/*
** MODIFIED_OR_ADDED
*/

char				*ft_itoa(int n);
int					ft_atoi(char *str);

int					ft_putstr_fd(char *str, int fd);

void				ft_putstr(char *str);
void				ft_strdel(char **ptr);

/*
** WELL_COMMENT
*/

size_t				ft_strlen(char *str);

int					ft_strncmp(char *str1, char *str2, size_t n);
char				*ft_strchr(char *str, int ch);
char				*ft_strrchr(char *str, int ch);
char				*ft_strnstr(char *str2, char *str1, size_t len);

void				ft_bzero(void *dest, size_t count);

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_isalnum(int c);
int					ft_isalpha(int ch);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

int					ft_tolower(int ch);
int					ft_toupper(int ch);

#endif
