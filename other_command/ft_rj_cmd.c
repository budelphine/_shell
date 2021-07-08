/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rj_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:20:00 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:31:27 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_check_dir(t_flag *flag)
{
	struct stat	buf;

	stat(flag->name, &buf);
	if (S_ISREG(buf.st_mode))
	{
		if (execve(flag->name, flag->param, g_env.g_env) == -1)
		{
			ft_putendl_fd(strerror(errno), 2);
			exit(126);
		}
	}
	if (S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd(flag->name, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
}

void	ft_execve(t_flag *flag, char *path)
{
	path = ft_get_key_value(ft_key_index("PATH"));
	if (!path || flag->name[0] == '.')
	{
		ft_check_dir(flag);
		ft_putstr_fd(flag->name, 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(127);
	}
	free(path);
	path = ft_valid_file(flag);
	if (!path)
	{
		if (ft_strncmp(flag->name, "exit", 5))
		{
			ft_putstr_fd(flag->name, 2);
			ft_putendl_fd(": command not found", 2);
		}
		exit(127);
	}
	if (execve(path, flag->param, g_env.g_env) == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit(g_env.g_status);
	}
}

int		ft_rj_cmd(t_flag *flag)
{
	pid_t	pid;

	if (!ft_strncmp(flag->name, "cd", 3))
		ft_cd(flag->param[1]);
	else if (!ft_strncmp("echo", flag->name, 5))
		ft_echo(flag);
	else if (!ft_strncmp(flag->name, "export", 7))
		ft_export(flag);
	else if (!ft_strncmp(flag->name, "pwd", 4))
		ft_pwd(flag);
	else if (!ft_strncmp(flag->name, "env", 4))
		ft_env(flag);
	else if (!ft_strncmp(flag->name, "unset", 6))
		ft_unset(flag);
	else
		ft_execve(flag, NULL);
	dup2(3, 0);
	dup2(4, 1);
	return (1);
}
