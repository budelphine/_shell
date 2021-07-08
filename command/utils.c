/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:10:41 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:30:33 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '=')
		return (0);
	while (g_env.g_env[i])
	{
		if (ft_check_len(arg, g_env.g_env[i]) &&
		!ft_strncmp(g_env.g_env[i], arg, ft_strlen_equal(arg))
		&& !ft_strchr(arg, '='))
			return (2);
		if (ft_check_len(arg, g_env.g_env[i]) &&
		!ft_strncmp(g_env.g_env[i], arg, ft_strlen_equal(arg))
		&& ft_strchr(arg, '='))
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_key(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '=')
		return (0);
	while (g_env.g_env[i])
	{
		if (!ft_strncmp(g_env.g_env[i], arg, ft_strlen_equal(arg) + 1))
			return (1);
		i++;
	}
	return (0);
}

void	ft_put_arg(char *arg)
{
	char	**tmp;
	int		i;
	int		k;

	k = -1;
	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_count_token(g_env.g_env) + 2));
	if (!tmp)
		ft_error(E_MLC, E_CODE, 2);
	while (g_env.g_env[i])
	{
		tmp[i] = g_env.g_env[i];
		i++;
	}
	tmp[i] = ft_strdup(arg);
	if (!tmp[i])
		ft_error(E_MLC, E_CODE, 2);
	tmp[++i] = NULL;
	free(g_env.g_env);
	g_env.g_env = tmp;
}

void	ft_change_arg(char *arg)
{
	int		i;
	int		index_val;

	index_val = ft_key_index(arg);
	i = 0;
	free(g_env.g_env[index_val]);
	g_env.g_env[index_val] = ft_strdup(arg);
	if (!g_env.g_env[index_val])
		ft_error(E_MLC, E_CODE, 2);
}

int		ft_valid_arg(char *arg, t_flag *flag)
{
	int	i;

	i = 0;
	if (!(arg[0] == '_' || ft_isalpha(arg[0])) || arg[0] == '=')
	{
		ft_print_nvi(arg, flag);
		return (0);
	}
	while (arg[i])
	{
		if (ft_isalnum(arg[i]) || arg[i] == '_' \
			|| arg[i] == '=' || arg[i] == '/')
			i++;
		else
		{
			ft_print_nvi(arg, flag);
			return (0);
		}
	}
	return (1);
}
