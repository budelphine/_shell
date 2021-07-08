/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:26:16 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:44:30 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_envp(int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = count - 1;
		while (j > i)
		{
			if (ft_strncmp(g_env.g_env[j - 1], g_env.g_env[j],
			ft_strlen(g_env.g_env[j - 1])) > 0)
				ft_swap(&g_env.g_env[j], &g_env.g_env[j - 1]);
			j--;
		}
		i++;
	}
}

void	ft_print_sort_envp(t_flag *flag)
{
	int		i;
	char	*tmp;

	i = 0;
	ft_sort_envp(ft_count_token(g_env.g_env));
	while (g_env.g_env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		tmp = ft_substr(g_env.g_env[i], 0, ft_strlen_equal(g_env.g_env[i]) + 1);
		ft_putstr_fd(tmp, 1);
		free(tmp);
		if (ft_strchr(g_env.g_env[i], '='))
			write(1, "\"", 1);
		tmp = ft_substr(g_env.g_env[i], ft_strlen_equal(g_env.g_env[i]) + 1,
		ft_strlen(g_env.g_env[i]));
		ft_putstr_fd(tmp, 1);
		free(tmp);
		if (ft_strchr(g_env.g_env[i], '='))
			write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
	if (flag->pipe)
		exit(0);
}

void	ft_export(t_flag *flag)
{
	int	i;

	i = 1;
	if (flag->count_param != 1)
	{
		while (flag->param[i])
		{
			if (!ft_check_arg(flag->param[i]))
			{
				if (ft_valid_arg(flag->param[i], flag))
					ft_put_arg(flag->param[i]);
				i++;
			}
			else if (ft_check_arg(flag->param[i]) == 2)
				return ;
			else
			{
				ft_change_arg(flag->param[i]);
				i++;
			}
		}
	}
	else
		ft_print_sort_envp(flag);
}
