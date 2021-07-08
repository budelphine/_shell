/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conveyor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:18:21 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:28:40 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_valid_file(t_flag *flag)
{
	char		**paths;
	int			i;
	char		*tmp_path;
	char		*tmp;
	struct stat	buf;

	i = -1;
	paths = ft_split(ft_get_key_value(ft_key_index("PATH")), ':');
	while (paths[++i])
	{
		tmp = paths[i];
		tmp_path = ft_strjoin(paths[i], "/");
		free(tmp);
		tmp = tmp_path;
		tmp_path = ft_strjoin(tmp_path, flag->name);
		free(tmp);
		stat(tmp_path, &buf);
		if (S_ISREG(buf.st_mode))
			return (tmp_path);
	}
	if (S_ISREG(buf.st_mode))
		return (flag->name);
	return (NULL);
}

int		ft_pipe_in(t_flag *flag, int pipe_out, int pipe_in)
{
	if (dup2(pipe_out, 1) == -1)
		ft_putendl_fd(strerror(errno), 2);
	close(pipe_out);
	close(pipe_in);
	ft_redirection(flag);
	if (!ft_rj_cmd(flag))
		g_env.g_status = 1;
	return (g_env.g_status);
}

void	ft_pipe_out(t_flag **flag, int pipe_out, int pipe_in)
{
	if (dup2(pipe_in, 0) == -1)
		ft_putendl_fd(strerror(errno), 2);
	close(pipe_in);
	close(pipe_out);
	*flag = (*flag)->next_pipe;
	waitpid(0, &g_env.g_status, 0);
}

void	ft_pipes(t_flag *flag)
{
	pid_t	pid;
	int		fd[2];

	while (flag->pipe)
	{
		if (pipe(fd) == -1)
			ft_error("Error pipe\n", E_CODE, 2);
		if (!(pid = fork()))
		{
			if (ft_pipe_in(flag, fd[1], fd[0]))
				exit(1);
		}
		else
			ft_pipe_out(&flag, fd[1], fd[0]);
	}
	ft_redirection(flag);
	if (!ft_rj_cmd(flag))
		exit(1);
}

int		ft_conveyor(t_flag *flag)
{
	pid_t	pid;

	if (!ft_strncmp(flag->name, "exit", 5) && !flag->pipe)
		ft_exit(flag);
	else
	{
		if (!(pid = fork()))
			ft_pipes(flag);
		else
		{
			waitpid(0, &g_env.g_status, 0);
			g_env.g_status = WEXITSTATUS(g_env.g_status);
		}
	}
	return (0);
}
