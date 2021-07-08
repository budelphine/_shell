/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:58:32 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:29:06 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_part(t_flag *flag, int flag_n)
{
	if (!flag_n)
		ft_putstr_fd("\n", 1);
	g_env.g_status = 0;
	if (flag->pipe)
		exit(0);
}

int		ft_valid_param(t_flag *flag, int i)
{
	if (!flag->param[i])
	{
		ft_putstr_fd("\n", 1);
		if (flag->count_param == 1 && flag->pipe == 1)
			exit(0);
		return (0);
	}
	return (1);
}

int		ft_echo(t_flag *flag)
{
	int	i;
	int	flag_n;

	flag_n = 0;
	i = 1;
	if (!ft_valid_param(flag, i))
		return (0);
	while (!ft_strncmp(flag->param[i], "-n ", 3))
	{
		flag_n = 1;
		i++;
	}
	if (!ft_strncmp(flag->param[i], "-n", 2) && ft_strlen(flag->param[i]) == 2)
	{
		flag_n = 1;
		i++;
	}
	while (flag->param[i])
	{
		ft_putstr_fd(flag->param[i], 1);
		i++;
	}
	ft_part(flag, flag_n);
	return (0);
}
