/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:24:17 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:27:48 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error_red(char *file)
{
	write(2, "`", 1);
	ft_putstr_fd(file, 2);
	write(2, "': ", 3);
	ft_putendl_fd(strerror(errno), 2);
	g_env.g_status = 1;
	exit(1);
}

void	ft_dir_red(t_flag *flag, int i)
{
	int	fd;
	int	mode;

	mode = 0755;
	if ((fd = open(flag->file[i], O_RDWR | O_CREAT | O_TRUNC, mode)) == -1)
		ft_error_red(flag->file[i]);
	if (i == flag->dir_red - 1)
	{
		if (dup2(fd, 1) == -1)
			ft_putendl_fd(strerror(errno), 2);
	}
	close(fd);
}

void	ft_rew_red(t_flag *flag, int i)
{
	int	fd;
	int	mode;

	mode = 0755;
	if ((fd = open(flag->file[i], O_APPEND | O_RDWR | O_CREAT, mode)) == -1)
		ft_error_red(flag->file[i]);
	if (i == flag->rew_red - 1)
	{
		if (dup2(fd, 1) == -1)
			ft_putendl_fd(strerror(errno), 2);
	}
	close(fd);
}

void	ft_rev_red(t_flag *flag, int i)
{
	int	fd;

	if ((fd = open(flag->file[i], O_RDONLY)) == -1)
		ft_error_red(flag->file[i]);
	if ((fd = open(flag->file[flag->rev_red - 1], O_RDONLY)) == -1)
		ft_error_red(flag->file[flag->rev_red - 1]);
	if (dup2(fd, 0) == -1)
		ft_putendl_fd(strerror(errno), 2);
}

int		ft_redirection(t_flag *flag)
{
	int	i;

	i = -1;
	while (flag->file[++i])
	{
		if (flag->red_i[i] == 1)
			ft_dir_red(flag, i);
		if (flag->red_i[i] == 0)
			ft_rev_red(flag, i);
		if (flag->red_i[i] == 2)
			ft_rew_red(flag, i);
	}
	return (1);
}
