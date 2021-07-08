/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:11:05 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:29:00 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_pwd(t_flag *flag)
{
	char	*buf;

	if (!(buf = getcwd(NULL, 0)))
	{
		ft_putendl_fd(strerror(errno), 2);
		g_env.g_status = 1;
		if (flag->pipe)
			exit(1);
		return (1);
	}
	else
		ft_putendl_fd(buf, 1);
	free(buf);
	g_env.g_status = 0;
	if (flag->pipe)
		exit(0);
	return (0);
}
