/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:28:33 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 21:01:28 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_start_command(t_flag *tmp)
{
	if (!ft_strncmp(tmp->name, C_EXIT, 5))
		ft_exit(tmp);
	ft_redirection(tmp);
	ft_rj_cmd(tmp);
}

void		ft_command(t_flag **flag)
{
	t_flag *tmp;

	tmp = *flag;
	if (tmp->pipe || !ft_cmd(tmp))
		ft_conveyor(tmp);
	else
		ft_start_command(tmp);
	ft_lst_clear(flag, &ft_remove_arr);
}
