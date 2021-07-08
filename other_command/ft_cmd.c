/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:33 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 20:18:03 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cmd(t_flag *flag)
{
	if (!ft_strncmp(flag->name, "cd", 3))
		return (1);
	else if (!ft_strncmp("echo", flag->name, 5))
		return (1);
	else if (!ft_strncmp(flag->name, "export", 7))
		return (1);
	else if (!ft_strncmp(flag->name, "pwd", 4))
		return (1);
	else if (!ft_strncmp(flag->name, "env", 4))
		return (1);
	else if (!ft_strncmp(flag->name, "unset", 6))
		return (1);
	return (0);
}
