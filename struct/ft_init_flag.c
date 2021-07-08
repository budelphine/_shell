/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:52:32 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 12:09:10 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_init_struct_flag(t_flag *flag)
{
	flag->cmd = 0;
	flag->end = 0;
	flag->semi = 0;
	flag->pipe = 0;
	flag->all_red = 0;
	flag->rev_red = 0;
	flag->dir_red = 0;
	flag->rew_red = 0;
	flag->count_param = 0;
	flag->next_pipe = NULL;
}

static void	ft_init_struct_mem(t_flag *flag)
{
	flag->name = NULL;
	flag->param = (char **)malloc(sizeof(char *) * 1);
	if (!flag->param)
		ft_error(E_MLC, E_CODE, E_FD);
	flag->param[0] = NULL;
	flag->red_i = (int *)malloc(sizeof(int) * 1);
	if (!flag->red_i)
		ft_error(E_MLC, E_CODE, E_FD);
	flag->red_i[0] = 0;
	flag->file = (char **)malloc(sizeof(char *) * 1);
	if (!flag->file)
		ft_error(E_MLC, E_CODE, E_FD);
	flag->file[0] = NULL;
}

t_flag		ft_init_flag(void)
{
	t_flag	flag;

	ft_init_struct_flag(&flag);
	ft_init_struct_mem(&flag);
	return (flag);
}
