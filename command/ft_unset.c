/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:53:54 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:30:16 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_error_unset(char *param)
{
	write(2, "unset: `", 8);
	ft_putstr_fd(param, 1);
	write(2, "'", 1);
	ft_putstr_fd(": not a valid identifier\n", 1);
	g_env.g_status = 1;
}

void	ft_del_arg(char *key)
{
	int		i;
	int		k;
	char	**tmp_env;

	k = 0;
	i = 0;
	tmp_env = (char **)malloc(sizeof(char *) * ft_count_token(g_env.g_env));
	while (g_env.g_env[i])
	{
		if (!ft_strncmp(g_env.g_env[i], key, ft_strlen_equal(g_env.g_env[i])))
			i++;
		else
		{
			tmp_env[k] = ft_strdup(g_env.g_env[i]);
			k++;
			i++;
		}
	}
	tmp_env[k] = NULL;
	i = -1;
	while (g_env.g_env[++i])
		free(g_env.g_env[i]);
	free(g_env.g_env);
	g_env.g_env = tmp_env;
}

void	ft_unset(t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->count_param > 1)
	{
		while (flag->param[++i])
		{
			if (!ft_strchr(flag->param[i], '=') && ft_check_arg(flag->param[i]))
			{
				if (ft_valid_arg(flag->param[i], flag))
					ft_del_arg(flag->param[i]);
			}
			else
			{
				if (ft_strchr(flag->param[i], '='))
					ft_print_error_unset(flag->param[i]);
				else
					ft_valid_arg(flag->param[i], flag);
			}
		}
	}
}
