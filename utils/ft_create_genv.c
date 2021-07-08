/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_genv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:27:08 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 22:32:59 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_create_genv(char **env)
{
	int k;
	int i;

	k = 0;
	i = -1;
	while (env[k])
		k++;
	g_env.g_env = (char **)malloc(sizeof(char *) * (k + 1));
	if (!g_env.g_env)
		ft_error(E_MLC, E_CODE, E_FD);
	g_env.g_env[k] = NULL;
	while (env[++i])
	{
		g_env.g_env[i] = ft_strdup(env[i]);
		if (!g_env.g_env[i])
			ft_error(E_MLC, E_CODE, E_FD);
	}
	return (0);
}
