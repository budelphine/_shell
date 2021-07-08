/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:09:14 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 23:03:59 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_end(int sig)
{
	int	pid;

	pid = waitpid(0, &g_env.g_status, WNOHANG);
	if (!pid)
	{
		ft_putstr_fd("\n", 1);
		kill(1, SIGINT);
	}
	else
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(S_PROMT, 1);
		g_env.g_status = 1;
	}
	(void)sig;
}

void	ft_quit(int sig)
{
	int		pid;

	g_env.g_status = 0;
	pid = waitpid(-1, &g_env.g_status, WNOHANG);
	if (!pid)
		ft_putstr("Quit: 3\n");
	(void)sig;
}
