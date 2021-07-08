/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:55:12 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:45:06 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "libft/libft.h"
# include "ft_parser.h"

typedef struct	s_glob
{
	char		**g_env;
	int			g_status;
}				t_glob;

t_glob			g_env;
/*
**		UTILS
*/

void			ft_err_cd(int res);
int				ft_count_token(char **arr);
int				ft_strlen_equal(char *str);
int				ft_check_arg(char *arg);
void			ft_put_arg(char *arg);
void			ft_change_arg(char *arg);
int				ft_valid_arg(char *arg, t_flag *flag);
int				ft_check_key(char *arg);
void			ft_minishell(void);
void			ft_print_nvi(char *arg, t_flag *flag);
int				ft_check_len(char *arg, char *env);
/*
**		BUILTINS COMMAND
*/

int				ft_echo(t_flag *flag);
void			ft_cd(char *path);
int				ft_pwd(t_flag *flag);
void			ft_export(t_flag *flag);
void			ft_unset(t_flag *flag);
int				ft_env(t_flag *flag);
void			ft_exit(t_flag *flag);

/*
**		NONE_BUILTINS COMMAND
*/
int				ft_conveyor(t_flag *flag);
int				ft_redirection(t_flag *file);
int				ft_rj_cmd(t_flag *flag);
char			*ft_valid_file(t_flag *flag);
int				ft_cmd(t_flag *flag);
void			ft_execve(t_flag *flag, char *path);

void			ft_end(int sig);
void			ft_quit(int sig);

#endif
