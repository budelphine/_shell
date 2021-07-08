/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:25:45 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 22:26:54 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_promt(void)
{
	ft_putstr_fd(S_PROMT, 1);
	return (1);
}

static void	ft_print_gnl_error(int flag)
{
	if (flag == 0)
		ft_error(C_EXIT, g_env.g_status, N_FD);
	if (flag == -1)
		ft_error(E_MLC, E_CODE, E_FD);
}

static void	ft_get_command(char *format)
{
	t_flag	*flag;
	int		res;

	res = 0;
	flag = NULL;
	if (ft_syntax_error(format))
		return ;
	while (*format)
	{
		flag = ft_parser(&format);
		if (!flag)
			break ;
		ft_command(&flag);
	}
}

void		ft_minishell(void)
{
	char	*format;
	int		res;

	signal(SIGINT, ft_end);
	signal(SIGQUIT, ft_quit);
	while (1)
	{
		while (ft_promt() && ((res = ft_get_line(&format)) > 0))
			ft_get_command(format);
		if (res == 0 || res == -1)
			ft_print_gnl_error(res);
	}
}
