/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:32:18 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:29:42 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(t_flag *flag)
{
	int	i;

	i = 0;
	while (g_env.g_env[i])
	{
		if (ft_strchr(g_env.g_env[i], '='))
		{
			ft_putstr_fd(g_env.g_env[i], 1);
			write(1, "\n", 1);
		}
		i++;
	}
	if (flag->pipe)
		exit(1);
	return (1);
}
