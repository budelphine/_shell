/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:02:15 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:28:54 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_count_token(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		ft_strlen_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

void	ft_err_cd(int res)
{
	if (res == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		g_env.g_status = 1;
	}
	else
		g_env.g_status = 0;
}

void	ft_print_nvi(char *arg, t_flag *flag)
{
	write(2, flag->name, ft_strlen(flag->name));
	write(2, ": `", 3);
	ft_putstr_fd(arg, 1);
	write(2, "'", 1);
	ft_putstr_fd(": not a valid identifier\n", 1);
	g_env.g_status = 1;
}

int		ft_check_len(char *arg, char *env)
{
	int	arg_len;
	int	env_len;

	arg_len = ft_strlen_equal(arg);
	env_len = ft_strlen_equal(env);
	if (arg_len == env_len)
		return (1);
	return (0);
}
