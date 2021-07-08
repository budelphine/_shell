/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:24:42 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:29:03 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_err(t_flag *flag)
{
	ft_putendl_fd("exit", 2);
	ft_putstr_fd(flag->param[0], 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(flag->param[1], 2);
	ft_putendl_fd(": numeric argument required", 2);
	exit(255);
}

int		ft_valid_exit_param(char *param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		if (ft_isdigit(param[i]) || (param[i] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_exit(t_flag *flag)
{
	if (flag->count_param == 1)
	{
		ft_putendl_fd("exit", 1);
		exit(g_env.g_status);
	}
	if (flag->count_param == 2)
	{
		if (ft_valid_exit_param(flag->param[1]))
		{
			ft_putendl_fd("exit", 1);
			exit(ft_atoi(flag->param[1]));
		}
		else
			ft_print_err(flag);
	}
	else
	{
		if (!ft_valid_exit_param(flag->param[1]))
			ft_print_err(flag);
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd(flag->param[0], 2);
		ft_putendl_fd(": too many arguments", 2);
		g_env.g_status = 1;
	}
}
